#include <bits/stdc++.h>
using namespace std;

char a[55][55],b[55][55];
bool ok[55][55];
int m,n;

int main() {
	scanf("%d %d",&n ,&m);
	memset(b,'0',sizeof(b));
	int sum = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	for(int i = 1;i < n; i++) {
			for(int j = 1;j < m; j++) {
				if(a[i][j] == '1' && a[i][j+1] == '1' && a[i+1][j] == '1' && a[i+1][j+1] == '1') {
					b[i][j] = '1'; b[i][j+1] = '1'; b[i+1][j] = '1'; b[i+1][j+1] = '1';
					ok[i][j] = 1; sum++;
				}
			}
		}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(b[i][j] != a[i][j]) {
				return puts("-1"), 0;
			}
		}
	}
		
	printf("%d\n", sum);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(ok[i][j]) {
				printf("%d %d\n", i, j);
			}
		}
	}
}