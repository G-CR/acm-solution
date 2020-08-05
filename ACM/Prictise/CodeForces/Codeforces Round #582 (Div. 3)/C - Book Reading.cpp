#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll q;
ll n,m,ans;

int main() {
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld %lld", &n, &m);
		ll t = n/m;
		if(m % 10 == 0) {
			puts("0");
			continue;
		}
		if(m % 2 == 0) {
			ans = t/5*20;
			t = t % 5;
			for(ll i = 1;i <= t; i++) {
				ans += m*i%10;
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(m % 5 == 0){
			ans = t/2*5;
			t = t%2;
			for(ll i = 1;i <= t; i++) {
				ans += m*i%10;
			}
			printf("%lld\n",ans);
			continue;
		}
		else{
			ans = t/10*45;
			t = t % 10;
			for(ll i = 1;i <= t; i++) {
				ans += m*i%10;
			}
			printf("%lld\n",ans);
			continue;
		}
	}
}