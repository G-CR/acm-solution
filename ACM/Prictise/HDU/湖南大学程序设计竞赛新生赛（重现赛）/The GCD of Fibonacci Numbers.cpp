#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int T;
ll a, b;
ll f[50];

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	f[1] = 1; for(int i = 2;i <= 45; i++) f[i] = f[i-1] + f[i-2];
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", f[gcd(a,b)]);
	}
}