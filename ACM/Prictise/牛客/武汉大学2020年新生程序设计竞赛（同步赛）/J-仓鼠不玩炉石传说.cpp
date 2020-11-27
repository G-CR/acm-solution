#include <bits/stdc++.h>
using namespace std;

int n, a, k;
int h[1003];

int main() {
	scanf("%d %d %d", &n, &a, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &h[i]);
	}
	
	int pos = n;
	for(int i = 1;i <= n; i++) {
		if(h[i] > k) {
			pos = i;
			break;
		}
	}
	
	int ans = 1;
	for(int i = 1;i <= n; i++) {
		if(i == pos) continue;
		if(h[i] <= k) {
			ans++;
			if(h[i] == k) break;
		}
		else break;
	}
	
	printf("%d\n", ans);
}