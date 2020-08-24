#include <bits/stdc++.h>
using namespace std;

int _;
long long tot, na, nv;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &tot, &na);
		nv = tot - na;
		long long ans = 0;
		int sta = 2;
		if(na%2 != 0) sta = 3;
		ans += (sta+na)*(na/2)/2;
		ans += (nv+1)/2;
		if(nv%2==0 && na%2 != 0) ans++;
		printf("%lld\n", ans);
	}
}