#include <bits/stdc++.h>
using namespace std;

int m,n,minx,miny,maxx,maxy;
char a[15][15];

int main() {
	while(~scanf("%d %d", &n, &m)) {
		minx = miny = 11; maxx = maxy = 0;
		bool ok = 0;
		for(int i = 1;i <= n; i++)
			for(int j = 1;j <= m; j++)
			{
				scanf(" %c", &a[i][j]);
				if(a[i][j] == '1') {
					ok = 1;
					maxx = max(maxx, i);
					maxy = max(maxy, j);
					minx = min(minx, i);
					miny = min(miny, j);
				}
			}
		for(int i = minx;i <= maxx; i++) {
			for(int j = miny;j <= maxy; j++) {
				if(a[i][j] == '0') {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		if(!ok) puts("No");
		else puts("Yes");
		
	}
}