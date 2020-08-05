#include <bits/stdc++.h>
using namespace std;

int n;
int a[2002];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d", &n);
	int num = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] == 1) num++;
	}
	if(num) {printf("%d\n", n-num); return 0;}
	
	int ans = 1e9;
	for(int i = 1;i <= n; i++) {
		int t = 0, sum = a[i];
		for(int j = i+1;j <= n; j++) {
			t++;
			sum = gcd(sum, a[j]);
			if(sum == 1) {
				ans = min(ans, t);
				break;
			}
		}
	}
	if(ans == 1e9) puts("-1");
	else printf("%d\n", ans+n-1);
}