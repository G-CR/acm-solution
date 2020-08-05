#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int ans[400005],n,k;

int main() {
	int head = 200002, tail = 200002, x;
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(mp[x] == 1) continue;
		ans[head--] = x;
		mp[x] = 1;
		if(tail - head > k) {
			mp[ans[tail--]] = 0;
		}
	}
	printf("%d\n", tail-head);
	for(int i = head+1;i <= tail; i++) printf("%d ", ans[i]);
	puts("");
}