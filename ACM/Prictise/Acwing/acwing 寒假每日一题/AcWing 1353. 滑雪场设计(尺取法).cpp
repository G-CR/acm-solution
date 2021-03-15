#include <bits/stdc++.h>
using namespace std;

int n;
int a[1003];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+1+n);
	int ans = 1e9;
	int l = a[1], r = l + 17;
	while(r <= a[n]) {
		int now = 0;
		for(int i = 1;i <= n; i++) {
			if(a[i] < l || a[i] > r) {
				int t = min(abs(a[i]-l), abs(a[i]-r));
				now += t * t;
			}
		}
		
		ans = min(ans, now);
		l++; r++;
	}
	
	printf("%d\n", ans);
}