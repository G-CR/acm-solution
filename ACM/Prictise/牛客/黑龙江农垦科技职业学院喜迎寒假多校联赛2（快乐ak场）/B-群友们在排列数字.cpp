#include <bits/stdc++.h>
using namespace std;

long long n, k;
bool vis[10];
int ans = 0;

void dfs(int p, long long now) {
	if(p == n) {
		if(now % k == 0) {
			ans++;
		}
		return;
	}
	for(int i = 0;i < n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(p+1, now*10+i);
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%lld %lld", &n, &k);
	
	dfs(0, 0);
	
	printf("%d\n", ans?ans:-1);
}