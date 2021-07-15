#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

struct node {
	ll p, w;
	bool operator < (const node &b) const {
		return p < b.p;
	}
} a[N];

int main() {
	int n;
	ll k;
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].p, &a[i].w);
	}
	
	sort(a+1, a+1+n);
	
	int pos = 1;
	ll ans = 0;
	while(k > 0) {
		if(pos > n) break;
		ll need = a[pos].p - ans;
		if(k >= need) {
			ans = a[pos].p;
			k -= need;
			k += a[pos].w;
		}
		else
			break;
		
		pos++;
	}
	
	ans += k;
	printf("%lld\n", ans);
}