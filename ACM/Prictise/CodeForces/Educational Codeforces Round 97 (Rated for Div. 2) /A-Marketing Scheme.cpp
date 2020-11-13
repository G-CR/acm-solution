#include <bits/stdc++.h>
using namespace std;

int _;
long long l, r;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &l, &r);
		double ans = r+1;
		if(l%(long long)ans >= ans/2.0) {
			puts("YES");
		}
		else puts("NO");
	}
}