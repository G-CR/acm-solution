#include <bits/stdc++.h>
using namespace std;

int _;
long long besum[100005], a[100005];
long long n, q, k, b, c;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &q);
		for(int i = 0;i < n; i++) {
			scanf("%lld", &a[i]);
		}
		
		besum[n-1] = a[n-1];
		for(int i = n-2;i >= 0; i--) {
			besum[i] = besum[i+1] + a[i];
		}
		
		long long sum = 0;
		for(int i = 0;i < n-1; i++) {
			sum += (a[i]*(n-1-i)-besum[i+1]);
		}
				
		printf("Case %d:\n", ++cas);
		
		while(q--) {
			scanf("%lld", &k);
			if(k == 1) {
				printf("%lld\n", sum);
			} 
			else {
				scanf("%lld %lld", &b, &c);
				long long t = c-a[b];
				a[b] = c;
				sum = sum - t*b + t*(n-b-1);
			}
		}
		
	}
}