#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int n, a;
int pre[N+5];
int son[N*25][2], idx;
int pos[N];

void insert(int x, int wh) {
	int p = 0;
	for(int i = 20;i >= 0; i--) {
		int& s = son[p][x>>i&1];
		if(!s) s = ++idx;
		p = s;
	}
	pos[p] = wh;
}

pair <int, int> query(int x) {
	int p = 0, res = 0;
	for(int i = 20; i >= 0; i--) {
		int s = x >> i & 1;
		if(son[p][!s]) {
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return {res, pos[p]};
}

int main() {
	scanf("%d", &n);
	int ans = 0, l, r;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a);
		pre[i] = pre[i-1] ^ a;
		insert(pre[i], i);
		auto t = query(pre[i]);
		if(t.first > ans) {
			ans = t.first;
			l = t.second+1;
			r = i;
		}
	}
	if(n == 1) {
		printf("%d 1 1\n", pre[1]);
		return 0;
	}
	if(l == 2 && r == 2) l = r = 1;
	printf("%d %d %d\n", ans, l, r);
}