#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int n;
long long a[100005], b[100005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b+1, b+1+n);
	
	long long ans = 1;
	int tail = n, j = n;
	while(tail) {
		if(a[tail] <= b[j] && j) {
			j = j>0?j-1:0;
			continue;
		}
		else {
			ans = (ans * (tail-j)) % mod;
			tail--;
		}
	}
	printf("%lld\n", ans);
}