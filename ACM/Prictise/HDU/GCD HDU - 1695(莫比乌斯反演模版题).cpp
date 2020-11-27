#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
bool check[MAX+10];  
int prime[MAX+10];  
int mu[MAX+10];  

void Mobius() {
	mu[1] = 1;  
	int tot = 0;  
	for(int i = 2; i <= MAX; i++) {
		if(!check[i]) {  
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

int a, b, c, d, k, _;

int main() {
	Mobius();
	scanf("%d", &_);
	int o = 0;
	while(_--) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		printf("Case %d: ", ++o);
		if(k == 0) {puts("0"); continue;}
		if(b > d) swap(b, d);
		b /= k; d /= k;
		long long ans1 = 0, ans2 = 0;
		for(int i = 1;i <= b; i++) {
			ans1 += (long long) mu[i] * (b/i) * (d/i);
			ans2 += (long long) mu[i] * (b/i) * (b/i);
		}
		printf("%lld\n",ans1-ans2/2);
	}
}