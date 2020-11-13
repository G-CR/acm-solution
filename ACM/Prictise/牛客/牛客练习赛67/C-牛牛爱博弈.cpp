#include <bits/stdc++.h>
using namespace std;

int _;
long long n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		if(n % 3 == 0) puts("Frame");
		else puts("Alan");
	}
}