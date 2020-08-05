#include <bits/stdc++.h>
using namespace std;

int _, n, a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		int num = 0, ans = 0, buzu = 0;
		for(int i = 1;i <= n; i++) {
			buzu = max(buzu, a[i]);
			num++;
			if(num >= buzu) {
				ans++;
				num = 0; buzu = 0;
			}
		}
		printf("%d\n", ans);
	}
}