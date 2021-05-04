#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
char s[103][103];

int main() {
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = y+1; i <= m; i++) {
		if(s[x][i] == '.') ans++;
		else break;
	}
	
	for(int i = y-1; i >= 1; i--) {
		if(s[x][i] == '.') ans++;
		else break;
	}
	
	for(int i = x+1; i <= n; i++) {
		if(s[i][y] == '.') ans++;
		else break;
	}
	
	for(int i = x-1; i >= 1; i--) {
		if(s[i][y] == '.') ans++;
		else break;
	}
	
	if(s[x][y] == '.') ans++;
	
	printf("%d\n", ans);
}