#include <iostream>
using namespace std;

int _;
long long n, m;

long long cal(long long i, long long j) {
	return i*i + 100000*i + j*j - 100000*j + i*j;
}

long long check(long long k) {
	long long num = 0;
	for(long long j = 1;j <= n; j++) {
		long long low = 0, high = n+1;
		while(high - low > 1) {
			long long mid = (low + high) / 2;
			long long t = cal(mid, j);
			if(t >= k) {
				high = mid;
			}
			else if(t < k) {
				low = mid;
			}
		}
		num += low;
	}
	return num;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &m);
		long long l = -1e12, r = 1e12;
		while(r - l > 1) {
			long long mid = (l + r) / 2;
			long long num = check(mid);
			if(num >= m) {
				r = mid;
			}
			else if(num < m) {
				l = mid;
			}
		}
		
		printf("%lld\n", l);
	}
}