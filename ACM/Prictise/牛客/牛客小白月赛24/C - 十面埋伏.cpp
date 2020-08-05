#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[505][505];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y) {
	a[x][y] = 'x';
	for(int i = 0;i < 4; i++) {
		int tx = x+dx[i], ty = y+dy[i];
		if(tx < 0 || ty < 0 || tx > n-1 || ty > m-1) continue;
		if(a[tx][ty] == '.') dfs(tx, ty);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n; i++) scanf("%s", a[i]);
	
	dfs(0,0);
	
	for(int i = 0;i < n; i++) {
		for(int j = 0;j < m; j++) {
			if(a[i][j] == '#') {
				for(int k = 0;k < 4; k++) {
					int tx = i+dx[k], ty = j+dy[k];
					if(a[tx][ty] == 'x') a[tx][ty] = '*';
				}
			}
		}
	}
	
	for(int i = 0;i < n; i++) {
		for(int j = 0;j < m; j++) {
			if(a[i][j] == 'x') a[i][j] = '.';
		}
	}
	
	for(int i = 0;i < n; i++) {
		for(int j = 0;j < m; j++) {
			printf("%c", a[i][j]);
		}
		puts("");
	}
}