#include <bits/stdc++.h>
using namespace std;

int _, n, m;
int a[102][102], b[102][102];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf("%d", &a[i][j]);
				if((i + j) % 2) b[i][j] = a[i][j]%2?a[i][j]+1:a[i][j];
				else b[i][j] = a[i][j]%2?a[i][j]:a[i][j]+1;
			}
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				printf("%d ", b[i][j]);
			}
			puts("");
		}
	}
}