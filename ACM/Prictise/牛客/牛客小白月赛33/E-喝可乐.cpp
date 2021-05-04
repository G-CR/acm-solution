#include <bits/stdc++.h>
using namespace std;

int a, b;

int solve(int p, int q) {
	int res = 0;
	while(p >= a || q >= b) {
		res += p - p % a;
		if(p >= a) {
			q += p / a;
			p = p % a;
		}
		
		res += q - q % b;
		if(q >= b) {
			p += q / b;
			q = q % b;
		}
	}
	res += p + q;
	return res;
}

int main() {
	int _; scanf("%d", &_); while(_--) {
		int n; scanf("%d %d %d", &n, &a, &b);
		int ans = 0;
		for(int i = 0; i <= n; i++) {
			ans = max(ans, solve(i, n-i));
		}
		printf("%d\n", ans);
	}
}