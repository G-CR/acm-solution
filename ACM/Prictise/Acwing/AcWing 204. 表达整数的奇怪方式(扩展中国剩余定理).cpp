#include <bits/stdc++.h>
using namespace std;

long long mod[100005], x[100005];
int n;

long long Exgcd(long long a,long long b,long long &x,long long &y) {
	if(!b) {x=1,y=0;return a;}
	long long gcd=Exgcd(b,a%b,y,x);
	y -= a/b*x;
	return gcd;
}

long long Ex_crt() {
	long long lcm=mod[1],last_x=x[1];
	for(int i=2;i<=n;i++) {
		long long lcm_a=((x[i]-last_x)%mod[i]+mod[i])%mod[i],x,y,k=lcm;
		long long gcd=Exgcd(lcm,mod[i],x,y);
		if(lcm_a%gcd) return -1; // 不存在的情况
		x=(x*lcm_a/gcd%(mod[i]/gcd)+(mod[i]/gcd))%(mod[i]/gcd);
		lcm=lcm*mod[i]/gcd,last_x=(last_x+k*x)%lcm;
	}
	return (last_x%lcm+lcm)%lcm;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld", &mod[i], &x[i]);
	}
	printf("%lld\n", Ex_crt());
}