#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		
		int head = 1, tail = 1;
		int ans = 0;
		while(head <= n) {
			if(a[tail] - a[head] <= k) {
				if(tail == n) break;
				tail++;
			}
			else {
				ans = max(ans, tail-head);
				head++;
			}
		}
		printf("%d\n", ans);
	}
}