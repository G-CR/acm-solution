#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5+7;

int n;
ll a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	
	ll ans = 0, pre = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + a[i] * a[i] % mod + pre * a[i] % mod) % mod;
		pre = (a[i] + pre * 2) % mod;
	}
	
	printf("%lld\n", ans);
}