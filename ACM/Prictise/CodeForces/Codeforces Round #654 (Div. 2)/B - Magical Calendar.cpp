#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll T;
	scanf("%lld", &T);
	while(T--){
		ll n, r;
		scanf("%lld %lld", &n, &r);
		ll Ans=0;
		if(n<=r){
			Ans=((1+n-1)*(n-1))/2+1;
		}
		else{
			Ans=(1+r)*r/2;
		}
		printf("%lld\n",Ans);
	}
}