#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,p,q;
ll a[40],s;
set<ll> sst;
map<ll,ll> mp;

int main() 
{
	scanf("%d %lld", &n, &s);
	for(int i = 0;i < n; i++) scanf("%lld", &a[i]);
	p = n/2; q = n-p;
	
	for(int i = 0;i < (1<<p); i++) {
		ll sum = 0;
		for(int j = 0;j < p; j++) if((i>>j) & 1) sum += a[j];	
		sst.insert(sum);
		mp[sum] = i;
	}
	
	for(int i = 0;i < (1<<q); i++) {
		ll sum = 0;
		for(int j = 0;j < q; j++) if((i>>j) & 1) sum += a[j+p];
		if(sst.find(s-sum) != sst.end()) {
			ll x = mp[s-sum];
			for(int j = 0;j < p; j++) printf("%d", (bool)(x&(1<<j)));
			for(int j = 0;j < q; j++) printf("%d", (bool)(i&(1<<j)));
			puts("");
			return 0;
		}
	}
}