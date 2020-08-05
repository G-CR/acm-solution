#include <bits/stdc++.h>
using namespace std;

int a[55],n,k,ans = 1e7+10;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
	sort(a+1,a+1+n);
	int t = 1;
	for(int i = 1;i <= 2e5; i++) {
		int num = 0,sum = 0;
		for(int j = 1;j <= n; j++) {
			int p = a[j], sumi = 0;
			while(p > 0) {
				if(p == i) {
					num++;
					sum += sumi;
					break;
				}
				p /= 2; sumi++;
				if(p == 0) sumi = 0;
			}
			if(num == k) {
				ans = min(ans, sum);
				break;
			}
		}
	}
	printf("%d\n", ans);
}