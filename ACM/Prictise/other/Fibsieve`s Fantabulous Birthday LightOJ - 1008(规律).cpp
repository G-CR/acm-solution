#include <bits/stdc++.h>
using namespace std;

int _;
long long n;

int main() {
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		printf("Case %d: ", ++cas);
		long long cnt = ceil(sqrt(n));
		long long t = cnt*cnt-(cnt-1);
		long long ansx = cnt, ansy = cnt;
		if(t == n) printf("%lld %lld\n", ansx, ansy);
		else {
			long long change = abs(t-n);
			if(cnt%2) {
				if(t < n) ansx -= change;
				else ansy -= change;
			}
			else {
				if(t < n) ansy -= change;
				else ansx -= change;
			}
			printf("%lld %lld\n", ansx, ansy);
		}
	}
}