#include <bits/stdc++.h>
using namespace std;

int n,r,q;
int x[100005];

int main() {
	scanf("%d", &q);
	while(q--) {
		int sum = 0;
		scanf("%d %d", &n, &r);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x[i]);
		}
		sort(x+1, x+1+n);
		
		int ans = 1, cnt = n-1;
		for(int i = 1;i <= n; i++) {
			if(x[cnt] == x[cnt+1]) {
				cnt--;
				continue;
			}
//			cout << "x = " << x[cnt] << endl;
			
			if(x[cnt] - r*ans <= 0) break;
			ans++; cnt--;
		}
		printf("%d\n", ans);
	}
}