#include <bits/stdc++.h>
using namespace std;

map <long long, pair<int, int> > mp;
int k, n, a[200005];

int main() {
	scanf("%d", &k);
	for(int i = 1;i <= k; i++) {
		long long sum = 0;
		scanf("%d", &n);
		for(int j = 1;j <= n; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		
		for(int j = 1;j <= n; j++) {
			long long t = sum-a[j];
			if(mp.find(t) == mp.end()) {
				mp[t] = make_pair(i, j);
			}
			else {
				if(i != mp[t].first) {
					puts("YES");
					printf("%d %d\n", mp[t].first, mp[t].second);
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
		
	}
	puts("NO");
}