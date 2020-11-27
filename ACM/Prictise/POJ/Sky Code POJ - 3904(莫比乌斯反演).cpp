#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int _, n, a[10004], num[10004];

const int MAX = 1e4;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10];

void Mobius() {
	memset(check,false,sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i = 2; i <= MAX; i++) {
		if( !check[i] ) {
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < tot; j++) {
			if(i * prime[j] > MAX) break;
			check[i * prime[j]] = true;
			if( i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}

void get_num() {
	memset(num, 0, sizeof num);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= sqrt((double)a[i]); j++) {
			if(a[i] % j == 0) {
				num[j]++; num[a[i]/j]++;
				if(j*j == a[i]) num[j]--;
			}
		}
	}
}

long long cal(int m) {
	return 1LL*m*(m-1)*(m-2)*(m-3) / 24;
}

int main() {
	Mobius();
	while(~scanf("%d", &n)) {
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		get_num();
		
		long long ans = 0;
		for(int i = 1;i <= 10000; i++) {
			ans += mu[i] * cal(num[i]);
		}
		
		printf("%lld\n", ans);
	}
}