https://ac.nowcoder.com/acm/contest/5986/E
#include <bits/stdc++.h>
using namespace std;

int L, n, m;
int a[50004];

bool check(int mid) {
	int cnt = 0, last = 0;
	for(int i = 1;i <= n+1; i++) {
		if(a[i]-last < mid) cnt++;
		else last = a[i];
	}
	return cnt <= m;
}

int main() {
	scanf("%d %d %d", &L, &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n+1] = L;
	
	int l = 0, r = L, ans = L;
	while(l <= r) {
		int mid = (l+r)/2;
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
//		cout << l << " " << r << endl; getchar();
	}
	
	printf("%d\n", ans);
}