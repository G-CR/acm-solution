#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
char x;
int n, m, num;
int a[1003][1003];
int tx[] = {0,0,-1,1};
int ty[] = {1,-1,0,0};
long long base1 = 23, base2 = 29;
long long hashx, hashy;
map <pair<long long, long long>, bool> vis;

void dfs(int x, int y) {
	for(int i = 0;i < 4; i++) {
		int nx = x + tx[i], ny = y + ty[i];
		if(a[nx][ny] == 1) {
			hashx = (hashx*base1+i) % mod;
			hashy = (hashy*base2+i) % mod;
			a[nx][ny] = 0;
			dfs(nx, ny);
		}
	}
	hashx = (hashx*base1+13) % mod;
	hashy = (hashy*base2+17) % mod;
}

int main() {
	while(~scanf("%d %d", &n, &m) && n) {
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &x);
				if(x == '1') a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		
		vis.clear();
		num = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				if(a[i][j] == 1) {
					hashx = 0; hashy = 0; num++;
					a[i][j] = 0;
					dfs(i, j);
					vis[{hashx, hashy}] = 1;
				}
			}
		}
		
		printf("%d %lu\n", num, vis.size());
	}
}