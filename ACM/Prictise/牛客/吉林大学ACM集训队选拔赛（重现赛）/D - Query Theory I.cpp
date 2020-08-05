#include <bits/stdc++.h>
using namespace std;

int _, l, r;
long long sum[1000006];

void init() {
	for(int i = 1;i <= 1e6; i++) {
		for(int j = i;j <= 1e6; j += i) {
			sum[j] += i;
		}
	}
	for(int i = 1;i <= 1e6; i++) {
		sum[i] += sum[i-1];
	}
}

int main() {
	init();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &l, &r);
		printf("%lld\n", sum[r]-sum[l-1]);
	}
}