#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

int main() {
	scanf("%lld", &n);
	ll k = n;
		int num = 0;
		while(k) {
			k /= 10;
			num++;
		}
		ll ans = 1;k = n;
		while(k) {
			ans *= k%10;
			k /= 10;
		}
		
		ll t, fin;
		for(int i = 1;i <= num; i++) {
			t = n; fin = 1;
			k = n % (ll)pow(10,i);
			t -= (k+1);
			while(t) {
				fin *= t%10;
				t /= 10;
			}
			ans = max(ans, fin);
		}
		printf("%lld\n", ans);
}