#include <bits/stdc++.h>
using namespace std;

long long m[20], a[20];
int _, n;

void exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {
		x = 1;
		y = 0;
	}
	else {
		exgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
}

long long CRT() {
	long long M = 1;
	for(int i = 1;i <= n; i++) M *= m[i];
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		long long x, y, Mi;
		Mi = M/m[i];
		exgcd(Mi, m[i], x, y);
		ans = (ans + a[i]*Mi*x) % M;
	}
	
	if(ans < 0) ans += M;
	return ans;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &m[i], &a[i]);
		}
		printf("Case %d: %lld\n", ++cas, CRT());
	}
}