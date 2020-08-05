#include <bits/stdc++.h>
using namespace std;

int _, n;
long long x[705], y[705], dis[500000];

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &x[i], &y[i]);
		}
		
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				dis[++cnt] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
		
		sort(dis+1, dis+1+cnt);
		int num = unique(dis+1, dis+1+cnt) - dis;
		printf("Case %d: %d\n", ++cas, num);
	}
}