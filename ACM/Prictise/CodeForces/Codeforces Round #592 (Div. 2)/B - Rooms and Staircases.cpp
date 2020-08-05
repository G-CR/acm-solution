#include <bits/stdc++.h>
using namespace std;

int t,n;
char s[1005];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		scanf("%s", s+1);
		if(s[1] == '1' || s[n] == '1') {
			printf("%d\n", 2*n);
			continue;
		}
		
		int start = 0,end = 0;
		for(int i = 1;i <= n; i++) {
			if(s[i] == '1') {
				start = i;
				break;
			}
		}
		for(int i = n; i >= 1; i--) {
			if(s[i] == '1') {
				end = i;
				break;
			}
		}
		int ans = n;
		if(start != 0) {
			ans = max(ans, 2*max(n-start+1, end));
		}
		printf("%d\n", ans);
	}
}
