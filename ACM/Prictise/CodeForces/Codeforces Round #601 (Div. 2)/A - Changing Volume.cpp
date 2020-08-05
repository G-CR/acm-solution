#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll a, b;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &a, &b);
		ll sum = 0;
		ll t = max(a,b)-min(a,b);
		if(t == 0) {
			printf("%lld\n", sum);
			continue;
		}
		if(t >= 5) {
			sum += t/5;
			t %= 5;
		}
		
		
		if(t == 0) {
			printf("%lld\n", sum);
			continue;
		}
		if(t >= 2) {
			sum += t/2;
			t %= 2;
		}
				
		if(t == 0) {
			printf("%lld\n", sum);
			continue;
		}
		sum += t;
		t = 0;
		printf("%lld\n", sum);
	}
}