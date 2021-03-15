#include <bits/stdc++.h>
using namespace std;

int n, m;
int r[1000006], d[1000006], s[1000006], t[1000006];
long long pre[1000006];

bool check(int mid) {
	for(int i = 1;i <= n; i++) pre[i] = 0;
	for(int i = 1;i <= mid; i++) {
		pre[s[i]] += d[i];
		pre[t[i]+1] -= d[i];
	}
	for(int i = 1;i <= n; i++) {
		pre[i] = pre[i-1] + pre[i];
		if(pre[i] > r[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &r[i]);
	}
	
	for(int i = 1;i <= m; i++) {
		scanf("%d %d %d", &d[i], &s[i], &t[i]);
	}
	
	int l = 1, r = m, ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid+1;
		}
		else {
			ans = mid;
			r = mid-1;
		}
	}
	
	if(ans == -1) puts("0");
	else {
		puts("-1");
		printf("%d\n", ans);
	}
	
}