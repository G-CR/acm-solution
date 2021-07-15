#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int _; scanf("%d", &_); while(_--) {
		ll n; scanf("%lld", &n);
		if(n % 2) puts("Odd");
		else {
			if(n % 4 == 0) puts("Even");
			else puts("Same");
		}
	}
}