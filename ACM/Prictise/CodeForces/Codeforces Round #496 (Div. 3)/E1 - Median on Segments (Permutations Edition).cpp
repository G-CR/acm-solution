#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
map <int, int> mp;

int main() {
	scanf("%d %d", &n, &m);
	int pos;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] == m) pos = i;
	}
	
	int cnt = 0;
	mp[cnt]++;
	for(int i = pos+1;i <= n; i++) {
		if(a[i] > m) cnt++;
		else cnt--;
		mp[cnt]++;
	}
	
	long long ans = mp[0]+mp[1];
	
	cnt = 0;
	for(int i = pos-1;i >= 1;i--) {
		if(a[i] < m) cnt++;
		else cnt--;
		ans += mp[cnt];
		ans += mp[cnt+1];
	}
	
	printf("%lld\n", ans);
}