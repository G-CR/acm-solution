#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int m, n, x, y, z, h;
long long a[2005], b[2005], ab[2005][2005];

int main() {
	scanf("%d %d %d", &n, &m, &h);
	while(h--) {
		scanf("%d %d %d", &x, &y, &z);
		a[x] += z;
		b[y] += z;
		ab[x][y] += z;
	}
	
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			ans = (ans + (a[i]+b[j]-ab[i][j])*(i+j)) % mod;
		}
	}
	printf("%lld\n", ans);
}