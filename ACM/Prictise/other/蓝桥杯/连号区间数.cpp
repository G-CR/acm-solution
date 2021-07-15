#include <bits/stdc++.h>
using namespace std;

int n, a[10004];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int ma = -1, mi = 1e9;
		for(int j = i; j <= n; j++) {
			ma = max(ma, a[j]);
			mi = min(mi, a[j]);
			if(ma-mi == j-i) {
//				printf("%d %d\n", i, j);
				ans++;
			} 
		}
	}
	
	printf("%d\n", ans);
}