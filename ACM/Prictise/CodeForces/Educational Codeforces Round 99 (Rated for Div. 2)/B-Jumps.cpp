#include <bits/stdc++.h>
using namespace std;

int _;
long long x;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &x);
		long long now = 0;
		long long cnt = 0;
		for(long long i = 1;now < x; i++) {
			now += i;
			cnt = i;
		}
		
		long long t = now-x;
		if(t == 1) cnt++;
		
		printf("%lld\n", cnt);
	}
}