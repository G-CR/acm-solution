#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll _;
ll n,l,k;
ll a[100007];
ll ok = 0, r = n-1, fuck, ans = 0, Ans2;

void fuck1() {
	ok=0, r=n-1, fuck = 0, ans=0;
	for(ll i=0;i<n;i++){
		if(l-(i%l)<=k){
			ok++;
			if(ok>=k){
				fuck=a[r];
				ans+=fuck;
			}
			r--;
		}
		else{
			if(ok>=k){
				ans+=fuck;
			}
		}
	}
}

void fuck2() {
	Ans2 = 0;
	k=l-k+1;
	r=0;
	ok=0;
	for(int i=0;i<n;i++){
		if(l-(i%l)<=k){
			ok++;
			if(ok>=k){
				fuck=a[r];
				Ans2+=fuck;
			}
			r++;
		}
		else{
			if(ok>=k){
				Ans2+=fuck;
			}
		}
	}
}

int main(){
	scanf("%lld",&_);
	while(_--) {
		scanf("%lld%lld%lld", &n, &l, &k);
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
		}
		sort(a,a+n);
		fuck1();
		fuck2();
		printf("%lld %lld\n",ans,Ans2);
	}
}