#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &x, &y, &n);
		long long t = n/x;
//		cout << "t = " << t << endl;
		if(t*x+y > n) t--;
		printf("%lld\n", t*x+y);
	}
}