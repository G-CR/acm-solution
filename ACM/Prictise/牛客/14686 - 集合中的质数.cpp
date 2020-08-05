#include <bits/stdc++.h>
using namespace std;

long long a[25], m, ans;
int n;

void dfs(long long now, int pos, int cnt) {
	if(now > m) return;
	if(cnt&1) ans += m/now;
	else ans -= m/now;
	for(int i = pos+1;i <= n; i++) {
		dfs(now*a[i], i, cnt+1);
	}
}

int main() {
	scanf("%d %lld", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for(int i = 1;i <= n; i++) {
		dfs(a[i], i, 1);
	}
	
	printf("%lld\n", ans);
}