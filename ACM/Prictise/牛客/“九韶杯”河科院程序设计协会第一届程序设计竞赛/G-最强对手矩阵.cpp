#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> a[200005], b[200005];

void cg() {
	if(n > m) {
		for(int i = 0;i <= m; i++) {
			b[i].resize(n+7);
		}
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				b[j][i] = a[i][j];
			}
		}
		swap(n,m);
	}
	else {
		for(int i = 0;i <= n; i++) {
			b[i].resize(m+7);
		}
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= m; j++) {
				b[i][j] = a[i][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			b[i][j] += b[i-1][j];
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0;i <= n; i++) {
		a[i].resize(m+7);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	cg();
	
	int ans = -1e9;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int now = 0;
			for(int k = 1; k <= m; k++) {
				now = max(now, 0) + b[j][k] - b[i-1][k];
				ans = max(ans, now);
			}
		}
	}
	
	printf("%d\n", ans);
}