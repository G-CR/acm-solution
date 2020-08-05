#include <bits/stdc++.h>
using namespace std;

char s[55][55];
int _, n;

bool check1(int x, int y) {
	bool zero = 0;
	for(int i = x;i <= n; i++) {
		if(s[i][y] == '0') zero = 1;
		if(s[i][y] == '1' && zero) return 0;
	}
	return 1;
}

bool check2(int x, int y) {
	bool zero = 0;
	for(int i = y;i <= n; i++) {
		if(s[x][i] == '0') zero = 0;
		if(s[x][i] == '1' && zero) return 0;
	}
	return 1;
}

bool check3(int x, int y) {
	if(s[x+1][y] == '0' && s[x][y+1] == '0') return 0;
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				scanf(" %c", &s[i][j]);
			}
		}
		
		bool ok = 1;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				if(s[i][j] == '1') {
					if(i == n || j == n) continue;
					if(!check3(i, j)) {
						ok = 0;
						break;
					}
					bool ok1 = check1(i, j);
					bool ok2 = check2(i, j);
					if(!ok1 && !ok2) {
						ok = 0; break;
					}
				}
			}
			if(!ok) break;
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}