#include <bits/stdc++.h>
using namespace std;

int n, _;
long long W;
pair<long long, int> w[200005];
vector <int> res;

int main() {
	scanf("%d", &_);
	while(_--) {
		res.clear();
		scanf("%d %lld", &n, &W);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &w[i].first);
			w[i].second = i;
		}
		sort(w+1, w+1+n);
		long long should = (W + 1) / 2;
		
		long long now = 0;
		for(int i = n;i >= 1; i--) {
			if(now >= should) break;
			if(now + w[i].first <= W) {
				now += w[i].first;
				res.push_back(w[i].second);
			}
		}
		if(now >= should) {
			printf("%d\n", (int)res.size());
			sort(res.begin(), res.end());
			for(int i: res) printf("%d ", i);
			puts("");
		}
		else puts("-1");
	}
	
}