#include <bits/stdc++.h>
using namespace std;

long long x;

int main() {
	scanf("%lld", &x);
	long long t = sqrt(x);
	if(abs((t+1)*(t+1)-x) < abs(t*t-x)) {
		t = t+1;
	}
	printf("%lld\n", t*t);
}