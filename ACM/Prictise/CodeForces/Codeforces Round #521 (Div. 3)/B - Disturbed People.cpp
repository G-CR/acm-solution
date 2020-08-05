#include <bits/stdc++.h>
using namespace std;

int n, a[105];

bool isDis(int i) {
	if(a[i-1] == 1 && a[i+1] == 1) return 1;
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] == 0) {
			if(isDis(i)) {
				a[i+1] = 0;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}