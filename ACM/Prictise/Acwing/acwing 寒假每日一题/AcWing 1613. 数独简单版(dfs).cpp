#include <bits/stdc++.h>
using namespace std;

char a[10][10];
bool row[10][10], col[10][10], sqr[3][3][10], hd[10][10];

void out() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			printf("%c", a[i][j]);
		}
		puts("");
	}
}

bool dfs(int r, int c) {
	if(r == 9) {out(); return 1;}
	if(c == 9) return dfs(r+1, 0);
	if(hd[r][c]) return dfs(r, c+1);
	for(int i = 1;i <= 9; i++) {
		if(!row[r][i] && !col[c][i] && !sqr[r/3][c/3][i]) {
			row[r][i] = col[c][i] = sqr[r/3][c/3][i] = 1;
			a[r][c] = i+'0';
			bool ok = dfs(r, c+1);
			if(ok) return 1;
			row[r][i] = col[c][i] = sqr[r/3][c/3][i] = 0;
			a[r][c] = '.';
		}
	}
	
	return 0;
}

int main() {
	for(int i = 0;i < 9; i++) {
		for(int j = 0;j < 9; j++) {
			scanf(" %c", &a[i][j]);
			if(a[i][j] != '.') {
				int t = a[i][j] - '0';
				row[i][t] = 1; 
				col[j][t] = 1;
				sqr[i/3][j/3][t] = 1;
				hd[i][j] = 1;
			}
		}
	}
	
	dfs(0,0);
}