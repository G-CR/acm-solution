#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[100005];
priority_queue <long long> q;
vector <long long> ans;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		if(a[i] % 2 == 0) q.push(a[i]);
		else ans.push_back(a[i]);
	}
	
	while(!q.empty() && k) {
		long long now = q.top(); q.pop();
		while(now % 2 == 0 && k && now >= q.top()) {
			now /= 2;
			k--;
		}
		if(now % 2) ans.push_back(now);
		else q.push(now);
	}
	while(!q.empty()) ans.push_back(q.top()), q.pop();
	
	long long res = 0;
	for(long long i: ans) res += i;
	printf("%lld\n", res);
}