#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n;
long long a[500005], sum;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld\n", &a[i]);
	}
	sort(a+1, a+1+n);
	
	for(int i = 1;i <= n; i++) {
		if(i <= n/2) {
			sum = (sum+a[i])%mod;
		}
		else sum = (sum*a[i])%mod;
	}
	printf("%lld\n", sum);
}