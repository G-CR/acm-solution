#include <bits/stdc++.h>
using namespace std;


int main() {
	long long ans = 1;
	for(int i = 0;;i++) {
		if(ans << i >= 10000) {
			printf("%lld", ans << i);
			printf("%d\n", i);
			break;
		}
	}
}