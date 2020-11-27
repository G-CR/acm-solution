#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10], pre[MAX+10];

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
	
	for(int i = 1;i <= MAX; i++) {
		pre[i] = pre[i-1] + mu[i];
	}
}

int _;
long long n, m, d;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &n, &m, &d);
		n /= d; m /= d;
		long long mi = min(n, m);
		long long ans = 0;
		long long l = 1, r;
		for(l = 1; l <= mi; l = r+1) {
			r = min(n/(n/l), m/(m/l));
			ans += (n/l) * (m/l) * (pre[r]-pre[l-1]);
		}
		
		printf("%lld\n", ans);
	}
}