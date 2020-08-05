#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: ", ++cas);
		int ans = 0;
		for(int i = 2;i <= n; i++) {
			ans = (ans+k)%i;
			cout << ans+1 << endl;
		}
		printf("%d\n", ans+1);
	}
}