#include <bits/stdc++.h>
using namespace std;

int nex[505][2005], len[505], T, n, ans;
char s[505][2005];
bool ok[505];

void get_next(int x) {
	nex[x][1] = 0;
	for(int i = 2, j = 0; i <= len[i]; i++) {
		while(j > 0 && s[x][i] != s[x][j+1]) j = nex[x][j];
		if(s[x][i] == s[x][j+1]) j++;
		nex[x][i] = j;
	}
}

bool kmp(int x, int y) {
	for(int i = 1, j = 0; i <= len[x]; i++) {
		while(j > 0 && (j == len[y] || s[x][i] != s[y][j+1])) j = nex[y][j];
		if(s[x][i] == s[y][j+1]) j++;
		if(j == len[y]) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		ans = -1;
		memset(ok, 0, sizeof(0));
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%s", s[i]+1);
			len[i] = strlen(s[i]+1);
			get_next(i);
		}
		
		for(int i = 2;i <= n-1; i++) {
			for(int j = 1;j <= i-1; j++) {
				if(ok[j] == 1) continue;
				if(kmp(i,j)) {
					ok[j] = 1;
				} 
			}
		}
		
		for(int i = n;i >= 2; i--) {
			for(int j = 1;j <= i-1; j++) {
				if(!ok[j] && !kmp(i,j)) {
					ans = i;
					break;
				}
			}
			if(ans > 0) break;
		}
		printf("Case #%d: %d\n", p, ans);
	}
}