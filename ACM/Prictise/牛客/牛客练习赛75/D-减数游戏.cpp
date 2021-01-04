#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n;
long long k, x;
priority_queue <long long, vector <long long>, greater<long long> > q;

int main() {
	scanf("%d %lld", &n, &k);
	long long ma = -1;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &x);
		ma = max(ma, x);
		q.push(x);
	}
	long long fin  = -1;
	while(q.size() > 1) {
		long long a = q.top(); q.pop();
		long long b = q.top(); q.pop();
		long long now = a*b;
		if(now > ma) {
			fin = (now%mod+k)%mod;
			break;
		}
		q.push(now+k);
		if(now > ma) break;
	}
	
	vector <long long> res;
	while(!q.empty()) {
		res.push_back(q.top());
		q.pop();
	}
	if(fin != -1) res.push_back(fin);
	
	for(int i = 1;i < res.size(); i+=2) {
		long long now = ((res[i]*res[i-1])%mod+k) % mod;
		res.push_back(now);
	}
	printf("%lld\n", res[res.size()-1]);
}