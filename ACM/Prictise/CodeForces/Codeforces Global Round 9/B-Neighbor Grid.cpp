#include <bits/stdc++.h>
using namespace std;

int _, n, m, a[305][305];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		bool ok = 1;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf("%d", &a[i][j]);
				if(a[i][j] > 4) ok = 0;
				if((i==1||i==n||j==1||j==m) && a[i][j] > 3) ok = 0;
			}
		}
		if(a[1][1]>2||a[1][m]>2||a[n][1]>2||a[n][m]>2) ok = 0;
		if(!ok) {puts("NO"); continue;}
		
		puts("YES");
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				if(i==1||i==n||j==1||j==m) a[i][j] = 3;
				else a[i][j] = 4;
			}
		}
		
		a[1][1]=2;a[1][m]=2;a[n][1]=2;a[n][m]=2;
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		} 
	}
}