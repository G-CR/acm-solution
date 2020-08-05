#include <bits/stdc++.h>
using namespace std;

int _;
long long w;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld", &w);
		printf("Case %d: ", ++cas);
		if(w % 2) puts("Impossible");
		else {
			long long t = w;
			while(w % 2 == 0) {
				w /= 2;
			}
			printf("%lld %lld\n", w, t/w);
		}
	}
}