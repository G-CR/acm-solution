#include <bits/stdc++.h>
#define ll long long
using namespace std;

int q;
ll a,b,n,s;

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%lld %lld %lld %lld", &a, &b, &n, &s);
		if(n*a+b < s) puts("NO");
		else {
			ll t1 = s % n;
			ll t2 = (s-t1) / n;
			if(min(a,t2)*n+b >= s) puts("Yes");
			else puts("No");
		}
	}
}