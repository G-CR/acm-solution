#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		double ans = 0;
		for(int i = 1;i <= n; i++) {
			ans += log10(i);
		}
		printf("%d\n", (int)ans+1);
	}
}