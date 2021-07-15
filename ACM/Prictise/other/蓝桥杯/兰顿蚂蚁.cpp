#include <bits/stdc++.h>
using namespace std;

int n, m, k, sx, sy;
int a[103][103];
char dir;
map <char, char> ri, le;


void dfs(int x, int y, char dir, int stp) {
	if(stp <= 0) {
		printf("%d %d\n", x, y);
		return;
	}
	
	char nd;
	if(a[x][y] == 1) nd = ri[dir];
	else nd = le[dir];
	a[x][y] = !a[x][y];
	
	if(nd == 'U') dfs(x-1, y, nd, stp-1);
	else if(nd == 'D') dfs(x+1, y, nd, stp-1);
	else if(nd == 'L') dfs(x, y-1, nd, stp-1);
	else if(nd == 'R') dfs(x, y+1, nd, stp-1);
}

int main() {
	ri['R'] = 'D'; ri['D'] = 'L'; ri['L'] = 'U'; ri['U'] = 'R';
	le['R'] = 'U'; le['U'] = 'L'; le['L'] = 'D'; le['D'] = 'R';
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d %c %d", &sx, &sy, &dir, &k);
	
	dfs(sx, sy, dir, k);
}