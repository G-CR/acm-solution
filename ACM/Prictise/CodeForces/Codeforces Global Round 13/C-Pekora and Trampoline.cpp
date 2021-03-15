#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[5005], fk[5005];

void cg(int l, int r) {
	for(int i = l; i <= r; i++) {
		fk[i]++;
	}
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			fk[i] = 0;
		}
		
		long long ans = 0;
		
		
		for(int i = 1;i <= n; i++) {
			if(a[i] != 1) {
				if(a[i] - fk[i] > 1) {
					ans += a[i] - fk[i] - 1;
				}
				else {
					fk[min(n, i+1)] += fk[i] - a[i] + 1;
				}
				if(i+2 <= n) cg(i+2, min(1ll*n, 1ll*i+a[i]));
			}
			else if(fk[i]) {
				fk[min(n, i+1)] += fk[i];
			}
		}
		
		printf("%lld\n", ans);
	}
}