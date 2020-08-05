#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
ll a[100005], b[100005];
vector <ll> ans;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n; i++) scanf("%lld", &b[i]);
	sort(a+1, a+1+n, cmp);
	sort(b+1, b+1+n, cmp);
	
	for(int i = 1;i <= k; i++) {
		ll t = a[i] + b[k-i+1];
		ans.push_back(t);
	}
	
	sort(ans.begin(), ans.end(), cmp);
	printf("%lld\n", ans[k-1]);
}
/*
4 4
13 12 11 2
18 17 16 1
*/
