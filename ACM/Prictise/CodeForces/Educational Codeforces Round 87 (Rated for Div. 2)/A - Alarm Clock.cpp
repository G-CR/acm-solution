#include <bits/stdc++.h>
using namespace std;

int _;
long long a, b, c, d;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if(b >= a) printf("%lld\n", b);
		else if(b < a && d >= c) puts("-1");
		else {
			int cnt = ceil((double)(a-b)/(double)(c-d));
//			cout << "cnt = " << cnt << endl;
			printf("%lld\n", b+cnt*c);
		}
	}
}