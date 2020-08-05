#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int T, n, m, w, u, v;
int dist[16][16];
int dp[16][1<<16];

int main() {
	scanf("%d", &T);
	while(T--) {
		for(int i = 0;i < 16; i++) for(int j = 0;j < 16; j++) dist[i][j] = inf;
		for(int i = 0;i < 16; i++) for(int j = 0;j < 1<<16; j++) dp[i][j] = inf;
		
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			dist[u][v] = dist[v][u] = min(dist[u][v], w);
		}
		for(int k = 0;k < n; k++) {
			for(int i = 0;i < n; i++) {
				for(int j = 0;j < n; j++) {
					if(i == j) dist[i][j] = 0;
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
		
		dp[0][1] = 0;
		for(int s = 1;s < (1<<n); s++) {
			for(int i = 0;(1<<i) <= s; i++) {
				if(s >> i & 1) {
					for(int k = 0;k < n; k++) {
						int s0 = s|(1<<k);
						dp[k][s0] = min(dp[k][s0], dp[i][s]+dist[i][k]);
					}
				}
			}
		}
		printf("%d\n", dp[0][(1<<n)-1]);
	}
}