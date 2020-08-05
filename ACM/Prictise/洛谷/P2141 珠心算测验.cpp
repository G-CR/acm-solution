#include <bits/stdc++.h>
using namespace std;

bool ok[100004];
int n, a[10004];
map<int, bool> mp;
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		ok[a[i]] = 1;
	}
	int ans = 0;
	sort(a+1, a+1+n);
	for(int i = 1;i <= n-1; i++) {
		for(int j = i;j <= n-1; j++) {
			if(a[i] == a[j]) continue;
			if(ok[a[i]+a[j]] && !mp[a[i]+a[j]]) {
				mp[a[i]+a[j]] = 1;
				ans++;
			} 
		}
	}
	printf("%d\n", ans);
}