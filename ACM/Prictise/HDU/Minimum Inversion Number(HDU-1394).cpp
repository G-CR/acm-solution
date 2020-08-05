#include <bits/stdc++.h>
using namespace std;

int n, a[5005];

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		}
		
		int now = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				if(a[i] > a[j]) now++;
			}
		}
		
		int ans = now;
		for(int i = 1;i <= n; i++) {
			now = now + ((n-1)-a[i]) - a[i];
	//		cout << now << endl;
			ans = min(ans, now);
		}
		
		printf("%d\n", ans);
	}
	
}