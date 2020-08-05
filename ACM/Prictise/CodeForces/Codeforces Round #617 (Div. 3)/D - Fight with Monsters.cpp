#include <bits/stdc++.h>
using namespace std;

int n, a, b, k;
int h[200005], cost[200005];

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &k);
	int sum = a+b;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &h[i]);
		int res = h[i] % sum;
		if(res == 0) {
			cost[i] = (sum-1)/a;
		}
		else {
			cost[i] = (res-1)/a;
		}
	}
	sort(cost+1, cost+1+n);
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		if(k >= cost[i]) {
			ans++;
			k -= cost[i];
		}
		else break;
	}
	
	printf("%d\n", ans);
}