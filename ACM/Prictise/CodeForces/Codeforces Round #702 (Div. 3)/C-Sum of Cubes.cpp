#include <bits/stdc++.h>
using namespace std;

int _;
long long x;
map <long long, int> mp;

int main() {
	for(long long i = 1;; i++) {
		if(i * i * i > 1e12) break;
		mp[i*i*i] = i;
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &x);
		bool ok = 0;
		for(long long i = 1;; i++) {
			long long i3 = i * i * i;
			if(i3 > x) break;
			long long t = x - i3;
			if(mp[t]) {
				ok = 1;
				break;
			}
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}