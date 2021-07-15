#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
const ll mod = 1e9+7;
int n;
ll a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	sort(a+1, a+1+n);
	n = unique(a+1, a+1+n) - (a+1);
	
	ll ans = 1;
	for(int i = n; i >= 1; i--) {
		ans = (ans * (a[i]-a[i-1]+1)) % mod;
	}
	
	printf("%lld\n", ans);
}