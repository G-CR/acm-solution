#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005], pre[200005];
map <long long, bool> mp;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i] = pre[i-1] + a[i];
	}
	
//	for(int i = 1;i <= n; i++) printf("%lld ", pre[i]); puts("");
	
	mp[0] = 1;
	int ans = 0,num=0;
	for(int i = 1;i <= n; i++) {
		if(mp[pre[i]-num] == 1) {
			num = pre[i-1];
			ans++;
			mp.clear();
			mp[0] = 1;
			mp[pre[i]-num] = 1;
			
		}
		else {
			mp[pre[i]-num] = 1;
		}
	}
	
	printf("%d\n", ans);
}