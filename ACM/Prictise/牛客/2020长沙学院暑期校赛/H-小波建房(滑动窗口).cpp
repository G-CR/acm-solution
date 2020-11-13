#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, _;
int h[1003][1003], mi1[1003][1003], mi2[1003][1003];
int pre[1003][1003];
deque <int> q;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf("%d", &h[i][j]);
			pre[i][j] = h[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &a, &b);
		for(int i = 1;i <= n; i++) {
			q.clear();
			for(int j = 1;j <= m; j++) {
				while(!q.empty() && h[i][q.back()] > h[i][j]) q.pop_back();
				q.push_back(j);
				while(j-q.front() >= b) q.pop_front();
				mi1[i][j] = h[i][q.front()];
			}
		}
		
		
		for(int j = 1;j <= m; j++) {
			q.clear();
			for(int i = 1;i <= n; i++) {
				while(!q.empty() && mi1[q.back()][j] > mi1[i][j]) q.pop_back();
				q.push_back(i);
				while(i-q.front() >= a) q.pop_front();
				mi2[i][j] = mi1[q.front()][j];
			}
		}
		
//		for(int i = 1;i <= n; i++) {
//			for(int j = 1;j <= m; j++) {
//				printf("%d ", mi2[i][j]);
//			}
//			puts("");
//		}
		
		long long ans = 1e18;
		for(int i = a;i <= n; i++) {
			for(int j = b; j <= m; j++) {
				ans = min(ans, (long long)pre[i][j]-pre[i-a][j]-pre[i][j-b]+pre[i-a][j-b]-mi2[i][j]*a*b);
			}
		}
		
		printf("%lld\n", ans);
	}
}