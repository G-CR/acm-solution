#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long x, n, pos;

int main() {
	scanf("%lld %lld %lld", &n, &x, &pos);
	int l = 0, r = n;
	int da = 0, xiao = 0;
	while(l < r) {
		int mid = (l+r) >> 1;
//		printf("mid = %d", mid);
		if(mid <= pos) {
			if(mid < pos) xiao++;
			l = mid+1;
//			printf(" l+1\n");
		}
		else {
			da++;
			r = mid;
//			printf(" r+1\n");
		}
	}
	
	long long ans = 1;
	for(long long i = 1;i <= n-da-xiao-1; i++) {
		ans = ans * i % mod;
	}
	
	int suoda = n - x;
	for(long long i = suoda;i > suoda-da; i--) {
		ans = ans * i % mod;
	}
	
	int suoxiao = x - 1;
	for(long long i = suoxiao;i > suoxiao-xiao; i--) {
		ans = ans * i % mod;
	}
	
	printf("%lld\n", ans);
}