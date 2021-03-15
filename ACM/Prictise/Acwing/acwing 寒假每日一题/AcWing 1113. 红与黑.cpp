#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[30][30];
int sx, sy;
int tx[] = {0,0,-1,1};
int ty[] = {-1,1,0,0};

int dfs(int x, int y) {
	int res = 0;
	for(int i = 0;i < 4; i++) {
		int nx = x+tx[i], ny = y+ty[i];
		if(a[nx][ny] == '.') {
			a[nx][ny] = '#';
			res += dfs(nx, ny) + 1;
		}
	}
	return res;
}

int main() {
	while(~scanf("%d %d", &m, &n) && n) {
		for(int i = 0;i <= n+1; i++) for(int j = 0;j <= m+1; j++) a[i][j] = '0';
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &a[i][j]);
				if(a[i][j] == '@') {
					sx = i; sy = j;
				}
			}
		}
		printf("%d\n", dfs(sx, sy)+1);
	}
}