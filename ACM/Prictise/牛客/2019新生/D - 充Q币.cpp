#include <bits/stdc++.h>
using namespace std;

int T;
long long a, b, n, s;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld %lld %lld", &a, &b, &n, &s);
		long long t1 = s % n;
		long long t2 = (s-t1) / n;
		if(min(a, t2)*n + b >= s) puts("YES");
		else puts("NO");
	}
}