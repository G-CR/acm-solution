#include <bits/stdc++.h>
using namespace std;

int n, m, q;
char s[3003][3003];
int fa[9000006], num[9000006];
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int getid(int x, int y) {
	return (x-1)*m+y;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1;i <= n*m; i++) fa[i] = i;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			for(int k = 0;k < 4; k++) {
				int tx = i+dirx[k], ty = j+diry[k];
				if(tx<1||tx>n||ty<1||ty>m||s[i][j]==s[tx][ty]) continue;
				int u = find(getid(i,j));
				int v = find(getid(tx,ty));
				fa[v] = u;
			}
		}
	}
	
//	for(int i = 1;i <= n; i++) {
//		for(int j = 1;j <= m; j++) {
//			printf("%d ", fa[getid(i,j)]);
//		}
//		puts("");
//	}
	
	for(int i = 1;i <= n*m; i++) num[find(i)]++;
	
	int stax, stay;
	while(q--) {
		scanf("%d %d", &stax, &stay);
		printf("%d\n", num[find(getid(stax, stay))]);
	}
}