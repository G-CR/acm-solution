#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000006];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
	int ans = 0, now = 1;
	for(int i = 2;i <= n; i++) {
		if(a[i] > a[i-1]) now++;
		else {
			ans = max(ans, now);
			now = 1;
		}
	}
	
	printf("%d\n", ans);
}