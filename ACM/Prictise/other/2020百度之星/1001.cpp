#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;

long long inv(long long a, long long b){  // b为模数 传参-2
	long long res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;  
	return res;
}

int main(){
	int _;
	scanf("%d", &_);
	while(_--){
		ll m, a, b;
		scanf("%lld %lld %lld", &m, &a, &b);
		ll ans = m;
		ans=((ans-(m*100-a)%mod*b%mod*inv(100*a,mod-2)%mod)%mod+mod)%mod;
		printf("%lld\n",ans);
	}
}