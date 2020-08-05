#include <bits/stdc++.h>
using namespace std;

int pre[1005], n, x;
map <int, int> mp;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		pre[i] = pre[i-1]^x;
	}
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 0;j < i; j++) {
			mp[pre[i]^pre[j]]++;
		}
		for(int j = i+1;j <= n; j++) {
			ans += mp[pre[j]^pre[i]];
		}
	}
	
	printf("%lld\n", ans);
}