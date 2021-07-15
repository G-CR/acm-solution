#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b;
ll k, f[100][100];

ll c(int n,int m) {
	if(n < m) return 0;
	if(f[n][m]) return f[n][m];
	for(int i = 0;i <= 60; i++) f[i][0] = 1;
	for(int i = 1;i <= 60; i++) {
		for(int j = 1;j <= n && j <= 30;j++) {
			f[i][j] = f[i-1][j-1] + f[i-1][j];
		}
	}
	return f[n][m];
}

void dfs(int a, int b, ll k) {
	ll tot = c(a+b-1, a-1);
	if(k == 1) {
		for(int i = 0; i < a; i++) printf("a");
		for(int i = 0; i < b; i++) printf("b");
		return;
	}
	else if(k > tot) {
		printf("b");
		dfs(a, b-1, k - tot);
	}
	else {
		printf("a");
		dfs(a-1, b, k);
	}
}

int main() {
	scanf("%d %d %lld", &a, &b, &k);
	dfs(a, b, k);
}