#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll n, x, y;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld %lld", &n, &x, &y);
		if(x >= (n+1)/2 && y >= n/2) puts("YES");
		else puts("NO");
	}
}