#include <bits/stdc++.h>
using namespace std;

int _, n, m;
int a[12][12];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		int num = 0, zero = 0;
		int mi = 10000;
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf("%d", &a[i][j]);
				if(a[i][j] < 0) num++;
				if(a[i][j] == 0) zero++;
				mi = min(mi, abs(a[i][j]));
			}
		}
		
//		cout << "mi = " << mi << endl;
		int ans = 0;
		if(num%2 == 0 || zero) {
			for(int i = 1;i <= n; i++) {
				for(int j = 1;j <= m; j++) {
					ans += abs(a[i][j]);
				}
			}
		}
		else {
			for(int i = 1;i <= n; i++) {
				for(int j = 1;j <= m; j++) {
					if(mi == abs(a[i][j])) {
						ans -= abs(mi);
						mi = 10000;
					} 
					else ans += abs(a[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
}