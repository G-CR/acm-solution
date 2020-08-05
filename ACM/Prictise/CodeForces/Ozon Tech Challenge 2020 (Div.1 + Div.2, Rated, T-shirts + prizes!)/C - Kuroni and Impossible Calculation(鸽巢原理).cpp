#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1005];

int main() {
	scanf("%d %d", &n, &m);
	if(n > 1000) return puts("0"), 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	long long ans = 1;
	for(int i = 1;i <= n-1; i++) {
		for(int j = i+1;j <= n; j++) {
			ans = (ans * (abs(a[i]-a[j]))) % m;
		}
	}
	
	printf("%lld\n", ans);
}