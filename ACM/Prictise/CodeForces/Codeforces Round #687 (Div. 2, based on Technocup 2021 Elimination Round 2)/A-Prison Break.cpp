#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m, r, c;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld %lld", &n, &m, &r, &c);
		long long ans1 = max(abs(n-r)+abs(m-c), abs(1-r)+abs(m-c));
		long long ans2 = max(abs(n-r)+abs(1-c), abs(1-r)+abs(1-c));
		printf("%lld\n",max(ans1, ans2)); 
	}
}