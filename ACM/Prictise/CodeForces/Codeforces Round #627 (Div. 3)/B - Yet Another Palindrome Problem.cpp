#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[5005], num[5005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) num[i] = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			num[a[i]]++;
		}
		bool ok = 0;
		for(int i = 1;i < n; i++) {
			if(num[a[i]] >= 2) {
				if(a[i+1] == a[i]) num[a[i]]--;
				if(num[a[i]] >= 2) {
					ok = 1;
					break;
				}
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}