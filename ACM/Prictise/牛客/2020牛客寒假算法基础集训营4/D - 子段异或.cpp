#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
long long a[200005];
map <long long, int> ok;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 2;i <= n; i++) {
		a[i] ^= a[i-1];
	}
	ok[0] = 1;
	for(int i = 1;i <= n; i++) {
		ans += ok[a[i]];
		ok[a[i]]++;
	}
	printf("%lld\n", ans);
	
//	for(int i = 1;i <= n; i++) printf("%lld ", a[i]);
//	puts("");
}

/*
9
1 2 3 2 1 2 3 2 1
*/