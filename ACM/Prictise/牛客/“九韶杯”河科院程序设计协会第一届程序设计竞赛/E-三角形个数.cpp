#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 20210411;

ll dao[N + 10];

int main() {
	dao[1] = 0, dao[2] = 1;
	for(int i = 3; i <= N; i++) {
		dao[i] = (dao[i-2] + (i-1)) % mod;
	}
	
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = (ans + 1ll * (1 + i) * i / 2) % mod;
		ans = (ans + dao[i]) % mod;
	}
	printf("%lld\n", ans);
}