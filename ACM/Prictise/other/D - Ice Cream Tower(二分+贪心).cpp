// https://vjudge.net/contest/347789#problem/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, k;
ll a[300005], b[300005];

bool judge(int x) {
	for(int i = 1;i <= x; i++) {
		a[i] = b[i];
	}
	
	int pos = x+1;
	for(int i = x+1;i <= x*k; i++) {
		while(pos <= n && a[i-x]*2 > b[pos]) pos++;
		if(pos == n+1) return 0;
		a[i] = b[pos]; pos++;
	}
	return 1;
}

int find(int l, int r) {
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(judge(mid)) l = mid;
		else r = mid-1;
	}
	return l;
}

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &b[i]);
		}
		sort(b+1, b+1+n);
		int ans = find(0, n/k);
		printf("Case #%d: %d\n", p, ans);
	}
}