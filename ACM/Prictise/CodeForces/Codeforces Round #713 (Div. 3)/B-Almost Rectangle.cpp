#include <bits/stdc++.h>
using namespace std;

int _, n;
char a[500][500];
int sx, sy, tx, ty;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		bool ok = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf(" %c", &a[i][j]);
				if(a[i][j] == '*') {
					if(!ok) {
						sx = i; sy = j; ok = 1;
					}
					else {
						tx = i; ty = j;
					}
				}
			}
		}
		
		int lx = min(sx, tx);
		int rx = max(sx, tx);
		int hy = max(sy, ty);
		int ly = min(sy, ty);
		if(lx == rx) {
			if(lx + 1 <= n) rx++;
			else rx--;
		}
		if(hy == ly) {
			if(hy + 1 <= n) hy++;
			else hy--;
		}
		
		a[lx][ly] = '*';
		a[lx][hy] = '*';
		a[rx][ly] = '*';
		a[rx][hy] = '*';
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				printf("%c", a[i][j]);
			}
			puts("");
		}
	}
}