#include <bits/stdc++.h>
using namespace std;

int q;
long long l1,r1,l2,r2;

int main() {
	scanf("%d", &q);
	while(q--) {
		
		scanf("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
		long long ans1 = l1, ans2;
		for(long long i = l2;i <= r2; i++) {
			if(i != ans1) {
				ans2 = i;
				break;
			}
		}
		printf("%lld %lld\n", ans1, ans2);
	}
}