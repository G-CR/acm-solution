#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

priority_queue <ll> q;

int main() {
	scanf("%d", &n);
	ll now = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ll x; scanf("%lld", &x);
		now += x; ans++;
		if(x < 0) q.push(abs(x));
		if(now < 0) {
			ans--;
			now += q.top();
			q.pop();
		}
	}
	
	printf("%d\n", ans);
}