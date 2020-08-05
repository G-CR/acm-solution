#include <bits/stdc++.h>
using namespace std;

int t;
long long a,b,k;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld %lld", &a, &b, &k);
		if(k % 2 == 0) {
			printf("%lld\n", k/2*(a-b));
		}
		else {
			printf("%lld\n", a+(k/2)*(a-b));
		}
	}
}