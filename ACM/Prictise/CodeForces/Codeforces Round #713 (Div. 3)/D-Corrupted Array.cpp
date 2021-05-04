#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _, n;
ll b[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n+2; i++) {
			scanf("%lld", &b[i]);
		}
		sort(b+1, b+n+3);
		
		ll sum = 0;
		for(int i = 1; i <= n; i++) sum += b[i];
		
		if(sum == b[n+1] || sum == b[n+2]) {
			for(int i = 1; i <= n; i++) {
				printf("%lld ", b[i]);
			} puts("");
		}
		else {
			sum += b[n+1];
			bool ok = 0;
			for(int i = 1; i <= n; i++) {
				if(sum - b[i] == b[n+2]) {
					ok = 1;
					for(int j = 1; j <= n; j++) {
						if(j == i) continue;
						printf("%lld ", b[j]);
					} printf("%lld\n", b[n+1]);
					break;
				}
			}
			
			if(!ok) {
				sum -= b[n+1]; sum += b[n+2];
				for(int i = 1; i <= n; i++) {
					if(sum - b[i] == b[n+1]) {
						ok = 1;
						for(int j = 1; j <= n; j++) {
							if(j == i) continue;
							printf("%lld ", b[j]);
						} printf("%lld\n", b[n+1]);
						break;
					}
				}
			}
			
			if(!ok) puts("-1");
		}
		
	}
}