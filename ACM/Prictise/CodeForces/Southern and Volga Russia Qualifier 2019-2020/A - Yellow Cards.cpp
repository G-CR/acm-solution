#include <bits/stdc++.h>
using namespace std;

int a1, a2, k1, k2, n;

int main() {
	scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);
	int t = n;
	t -= ((k1-1)*a1 + (k2-1)*a2);
	if(t <= 0) {
		printf("0 ");
	} else {
		printf("%d ",t);
	}
	
	t = n;
	int ans = 0;
		if(k1 < k2) {
			while(a1-- && t >= k1) {
				t -= k1;
				ans++;
			}
			while(a2-- && t >= k2) {
				t -= k2;
				ans++;
			}
		} else {
			while(a2-- && t >= k2) {
				t -= k2;
				ans++;
			}
			while(a1-- && t >= k1) {
				t -= k1;
				ans++;
			}
			
		}
		printf("%d\n", ans);
}