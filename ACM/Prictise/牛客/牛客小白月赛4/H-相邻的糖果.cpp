#include <bits/stdc++.h>
using namespace std;

int n, m;
long long x, a[1000006];

int main() {
	scanf("%d %d %lld", &n, &m, &x);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	int l = 1, r = 0;
	long long sum = 0, ans = 0;
	while(r <= n) {
		if(r-l+1 < m) {
			r++;
			sum += a[r];
		}
		else {
			if(sum > x) {
				int pos = r;
				long long t = sum-x;
				while(t) {
					long long mi = min(a[pos], t);
					a[pos] -= mi;
					t -= mi;
					ans += mi;
					if(a[pos] == 0) pos--;
				}
				sum = x;
			}
			
			sum -= a[l]; l++;
			r++; sum += a[r];
		}
	}
	
	printf("%lld\n", ans);
}