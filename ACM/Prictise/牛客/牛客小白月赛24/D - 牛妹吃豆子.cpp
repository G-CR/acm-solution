#include <bits/stdc++.h>
using namespace std;

int n, m, k, q, w1, h1, w2, h2;
long long val[2002][2002];

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	while(k--) {
		scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
		val[w1][h1]++;
		val[w1][h2+1]--;
		val[w2+1][h1]--;
		val[w2+1][h2+1]++;
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			val[i][j] = val[i][j] + val[i-1][j] + val[i][j-1] - val[i-1][j-1];
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			val[i][j] = val[i][j] + val[i-1][j] + val[i][j-1] - val[i-1][j-1];
		}
	}
	
	while(q--) {
		scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
		printf("%lld\n", val[w2][h2]-val[w1-1][h2]-val[w2][h1-1]+val[w1-1][h1-1]);
	}
}