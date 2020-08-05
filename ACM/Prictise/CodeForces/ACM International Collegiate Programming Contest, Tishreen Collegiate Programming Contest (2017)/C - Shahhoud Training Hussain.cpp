#include <bits/stdc++.h>
using namespace std;

long long T, k, p ,n;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld %lld", &k, &p, &n);
		long long t = (k-p)*n;
		if(t < 0) t = 0;
		printf("%lld\n", t);
	}
}