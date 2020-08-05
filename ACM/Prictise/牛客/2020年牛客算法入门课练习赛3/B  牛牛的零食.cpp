#include <bits/stdc++.h>
using namespace std;

int n, a, b, x[20], ans;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

void dfs(int t, int pos, long long di, bool ok) {
	if(pos == n+1) {
		if(ok) ans -= t/di;
		else ans += t/di;
		return;
	}
	dfs(t, pos+1, di, ok);
	dfs(t, pos+1, di*x[pos]/gcd(di,x[pos]), ok^1);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x[i]);
	}
	scanf("%d %d", &a, &b);
	dfs(a-1,1,8,0); ans = -ans;
	dfs(b,1,8,0);
	
	printf("%d\n", ans);
}