#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
pair <ll, ll> chs[200005];
long long pre1[200005], pre2[200005];

bool cmp1(pair<ll, ll> a, pair<ll, ll> b) {
	if(a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

bool cmp2(pair<ll, ll> a, pair<ll, ll> b) {
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main() {
	long long ans = 1e18;
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld", &chs[i].first);
	for(int i = 1;i <= n; i++) scanf("%lld", &chs[i].second);
	
	sort(chs+1, chs+1+n, cmp1);
	for(int i = 1;i <= n; i++) {
		pre1[i] = pre1[i-1] + chs[i].second;
	}
	for(int i = 1;i <= n; i++) {
		ans = min(ans, pre1[i-1]+chs[i].first);
	}
	
	sort(chs+1, chs+1+n, cmp2);
	for(int i = 1;i <= n; i++) {
		pre2[i] = pre2[i-1] + chs[i].first;
	}
	for(int i = 1;i <= n; i++) {
		ans = min(ans, pre2[i-1]+chs[i].second);
	}
	printf("%lld\n", ans);
}