#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int son[1000005][2], idx;

void insert(int x) {
	int p = 0;
	for(int i = 30; ~i; i--) {
		int& s = son[p][x>>i&1];
		if(!s) s = ++idx;
		p = s;
	}
}

int query(int x) {
	int p = 0, res = 0;
	for(int i = 30; ~i; i--) {
		int s = son[p][!(x>>i&1)];
		if(!s) s = son[p][x>>i&1];
		else res += 1 << i;
		p = s;
	}
	return res;
}


int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}
	
	int ans = -1;
	for(int i = 1;i <= n; i++) ans = max(ans, query(a[i]));
	
	printf("%d\n", ans);
}