#include <bits/stdc++.h>
using namespace std;

int _;
long long x[3], y[3];

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> x[1] >> y[1] >> x[2] >> y[2];
		long long num1 = x[2]-x[1]+1;
		long long num2 = y[2]-y[1]+1;
		printf("%lld\n", num1*num2);
	}
}