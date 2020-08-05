#include <bits/stdc++.h>
using namespace std;

int n, k;
int L[200005];

int main() {
	scanf("%d %d", &n, &k);
	int l = 1, r = 1;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &L[i]);
		r = max(r, L[i]);
	}
	
	int ans;
	while(l <= r) {
		int mid = (l+r)/2;
		int num = 0;
		for(int i = 1;i <= n; i++) {
			num += L[i]/mid;
		}
		
		if(num >= k) {
			l = mid+1;
			ans = max(ans, mid);
		}
		else {
			r = mid-1;
		}
	}
	printf("%d\n", ans);
}