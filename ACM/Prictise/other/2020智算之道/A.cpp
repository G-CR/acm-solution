#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

ll a,b;

int main(){
	scanf("%lld %lld", &a, &b);
	ll aa = a ,h = 1;
	while(aa > 0) {
		aa /= 10;
		h *= 10;
	}
	
	int ans=0;
	for(ll i = 100;i <= 999; i++){
		if((a+i*h)%b==0){
			ans++;
		}
	}
	
	printf("%d\n",ans);
}