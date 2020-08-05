#include <bits/stdc++.h>
using namespace std;

int q;
long long h,n,a[200005];

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%lld %lld", &h, &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		int ans = 0;
		for(int i = 1;i <= n;) {
			if(i == n) break;
			if(i == n-1){
				if(a[n] > 1) {
					ans++;
				}
				break;
			}
			
			if(a[i+1] - a[i+2] == 1) {
				i+=2;
			} else {
				i++;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}