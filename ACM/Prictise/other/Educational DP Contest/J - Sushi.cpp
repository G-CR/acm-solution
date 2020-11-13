#include <bits/stdc++.h>
using namespace std;

int n, num[4];
double dp[303][303][303];

double dfs(int a, int b, int c) {
	if(a == 0 && b == 0 && c == 0) return 0;
	if(dp[a][b][c] >= 0) return dp[a][b][c];
	int sum = a + b + c;
	double ans = 1.0*n/sum;
	if(a) ans += 1.0*dfs(a-1, b, c)*a/sum;
	if(b) ans += 1.0*dfs(a+1, b-1, c)*b/sum;
	if(c) ans += 1.0*dfs(a, b+1, c-1)*c/sum;
	
	return dp[a][b][c] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1, x;i <= n; i++) {
		scanf("%d", &x);
		num[x]++;
	}
	
	printf("%.15lf\n", dfs(num[1], num[2], num[3]));
}