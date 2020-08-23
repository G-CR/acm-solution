#include <bits/stdc++.h>
using namespace std;

int _, n, cas;

int main() {
	scanf("%d", &_);
	while(_--) {
		long long ans = 0;
		scanf("%d", &n);
		for(int i = 1,r = 0;i <= n; i = r+1) {
			if(n/i == 0) break;
			r = n/(n/i);
			ans += (r-i+1)*(n/i);
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	
}