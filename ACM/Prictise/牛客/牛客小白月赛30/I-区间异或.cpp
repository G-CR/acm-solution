#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[3004], ma[3004], x;

bool check(long long mid) {
	if(ma[mid] >= x) return 1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for(int len = 1;len <= n; len++) {
		int l = 1, r = l+len-1;
		long long now = a[l];
		for(int i = l+1;i <= r; i++) {
			now ^= a[i];
		} ma[len] = now;
		while(r <= n) {
			now ^= a[l]; l++;
			r++; now ^= a[r];
			ma[len] = max(ma[len], now);
		}
	}
	for(int i = 1;i <= n; i++) ma[i] = max(ma[i], ma[i-1]);
	
	while(m--) {
		scanf("%lld", &x);
		int l = 1, r = n, ans = -1;
		while(l <= r) {
			int mid = (l+r) / 2;
			if(check(mid)) {
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		printf("%d\n", ma[ans] >= x?ans:-1);
	}
}