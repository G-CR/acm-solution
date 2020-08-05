#include <bits/stdc++.h>
using namespace std;

long long n;
char s[300005];

int main() {
	scanf("%lld", &n);
	scanf("%s", s+1);
	long long ans = n*(n-1)/2;
	
	int pre = 1;
	for(int i = 2;i <= n; i++) {
		if(s[i] == s[i-1]) continue;
		ans++;
		ans -= (i-pre);
		pre = i;
	}
	
	pre = n;
	for(int i = n-1; i >= 1; i--) {
		if(s[i] == s[i+1]) continue;
		ans -= (pre-i);
		pre = i;
	}
	printf("%lld\n", ans);
}