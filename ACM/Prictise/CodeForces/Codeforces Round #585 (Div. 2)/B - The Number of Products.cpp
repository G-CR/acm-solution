#include <bits/stdc++.h>
using namespace std;

int num[2][200005],n,x;
long long ans0,ans1;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(x > 0) {
			num[0][i] = num[0][i-1] + 1;
			num[1][i] = num[1][i-1];
		}
		else {
			num[0][i] = num[1][i-1];
			num[1][i] = num[0][i-1] + 1;
		}
		ans0 += num[0][i];
		ans1 += num[1][i];
	}
	printf("%lld %lld\n", ans1, ans0);
}