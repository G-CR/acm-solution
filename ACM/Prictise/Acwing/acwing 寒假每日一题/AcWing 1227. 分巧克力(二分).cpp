#include <bits/stdc++.h>
using namespace std;

int n, k;
int h[100005], w[100005];

bool check(int mid) {
	int res = 0;
	for(int i = 1;i <= n; i++) {
		int heng = h[i] / mid;
		int shu = w[i] / mid;
		res += heng * shu;
		if(res >= k) return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &k);
	int ma = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &h[i], &w[i]);
		if(w[i] > h[i]) swap(h[i], w[i]);
		ma = max(ma, w[i]);
	}
	
	int l = 1, r = ma, ans;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	
	printf("%d\n", ans);
}