#include <bits/stdc++.h>
using namespace std;

int _, n, a[55];
bool vis[55];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int odd = 0, even = 0;
		for(int i = 1;i <= n; i++) {
			vis[i] = 0;
			scanf("%d", &a[i]);
			if(a[i]%2) odd++;
			else even++;
		}
		if(odd%2 == 0 && even%2 == 0) puts("YES");
		else {
			bool ok = 0;
			for(int i = 1;i <= n; i++) {
				for(int j = i+1;j <= n; j++) {
					if(abs(a[i]-a[j]) == 1) {
						odd--, even--;
						ok = 1;
						break;
					} 
				}
				if(ok) break;
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
}