#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	
	int ans = 1, last = 1;
	for(int i = 2;i <= n; i++) {
		if(a[i]-a[last] <= 5) {
			ans = max(ans, i-last+1);
		}
		else {
			ans = max(ans, i-last);
			while(last < i) {
				last++;
				if(a[i]-a[last] <= 5) break;
			}
		}
	}
	
	printf("%d\n", ans);
}