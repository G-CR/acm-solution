#include <bits/stdc++.h>
using namespace std;

int T;
long long p;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &p);
		p--;
		if(p % 3) puts("NO");
		else {
			p /= 3;
			long long x = sqrt(p);
			long long y = sqrt(p)+1;
			if(x * y == p) puts("YES");
			else puts("NO");
		}
	}
}