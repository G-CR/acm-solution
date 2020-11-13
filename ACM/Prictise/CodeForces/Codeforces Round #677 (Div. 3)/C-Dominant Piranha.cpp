#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[300005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		long long size = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			size = max(size, a[i]);
		}
		
		long long ans = -1;
		for(int i = 1;i <= n; i++) {
			if(a[i] == size) {
				if(i == 1) {
					if(a[i+1] < a[i]) {
						ans = i;
						break;
					}
				}
				else if(i == n){
					if(a[i] > a[i-1]) {
						ans = i;
						break;
					}
				}
				else {
					if(a[i] > a[i-1] || a[i] > a[i+1]) {
						ans = i;
						break;
					}
				}
			}
		}
		
		printf("%lld\n", ans);
	}
}