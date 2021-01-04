#include <bits/stdc++.h>
using namespace std;

int _, n, x;
int a[505];

bool nice() {
	for(int i = 2;i <= n; i++) if(a[i] < a[i-1]) return 0;
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &x);
		bool need = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			if(i>1 && a[i]<a[i-1]) need = 1;
		}
		if(!need) {
			puts("0");
			continue;
		}
		
		int ans = 0; bool ok = 0;
		for(int i = 1;i <= n; i++) {
			if(x < a[i]) {
				swap(x, a[i]);
				ans++;
				if(nice()) {
					ok = 1;
					break;
				} 
			}
		}
		
		if(ok) printf("%d\n", ans);
		else puts("-1");
	}
}