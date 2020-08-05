#include <bits/stdc++.h>
using namespace std;

int T;
long long x, y;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &x, &y);
		long long t = x - y;
		bool ok = 0;
		if(t <= 1) puts("NO");
		else puts("YES");
	}
}