#include <bits/stdc++.h>
using namespace std;

int t;
long long a, b;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &a, &b);
		long long num = 0;
		for(long long i = 0;; i *= 10) {
			i += 9;
			if(i > b) break;
			else {
				num++;
			}
		}
		printf("%lld\n", a*num);
	}
}