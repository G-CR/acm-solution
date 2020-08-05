#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
char mp[105][105];

void dfs(int a,int b) {
	mp[a][b] = '.';
	for(int i = -1;i <= 1; i++) {
		for(int j = -1;j <= 1; j++) {
//			if(i == 0 && j == 0) continue;
			if(mp[a+i][b+j] == 'W') {
				dfs(a+i,b+j);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &mp[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(mp[i][j] == 'W') {
				ans++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n", ans);
}