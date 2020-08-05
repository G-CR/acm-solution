#include<stdio.h>
#define ll long long

ll k, mul[50];

void sta() {
	ll x = 1;
	for(int i = 1;i <= 19; i++) {
		x *= i;
		mul[i] = x;
	}
}

int main() {
	sta();
	int p = 1,ans1,ans2;
	
	while(~scanf("%lld", &k)) {
		bool ok = 0;
		printf("Case %d: ", p++);
		if(k == 1) {
			puts("Impossible");
			continue;
		}
		for(int i = 2;i <= 19; i++) {
			for(int j = 1;j <= i; j++) {
				if(mul[i]/mul[j] < k) break;
				if(mul[i]/mul[j] == k) {
					ans1 = i,ans2 = j;
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) printf("%d %d\n", ans1, ans2);
		else {
			printf("%lld %lld\n",k, k-1);
		}
	}
}