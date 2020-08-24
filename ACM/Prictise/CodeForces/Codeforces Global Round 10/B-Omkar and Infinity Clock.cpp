#include <bits/stdc++.h>
using namespace std;

int _, n;
long long k, a[200005];

vector <long long> one, two;


int main() {
	scanf("%d", &_);
	while(_--) {
		one.clear(); two.clear();
		scanf("%d %lld", &n, &k);
		long long ma = -1e18;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			ma = max(ma, a[i]);
		}
		for(int i = 1;i <= n; i++) {
			long long x = ma-a[i];
			one.push_back(x);
		}
		
		ma = -1e18;
		for(long long i: one) {
			ma = max(ma, i);
		}
		
		for(long long i: one) {
			long long x = ma-i;
			two.push_back(x);
		}
		
		if(k%2==1) for(long long i : one) printf("%lld ", i);
		else for(long long i : two) printf("%lld ", i);
		puts("");
	}
}