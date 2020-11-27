#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool check[MAX+10];
int prime[MAX+10], g[MAX+10], mu[MAX+10], sum[MAX+10];
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
	
	for(int i = 0;i < tot; i++) {
		for(int j = 1; j * prime[i] <= MAX; j++) {
			g[j * prime[i]] += mu[j];
		}
	}
	for(int i = 1;i <= MAX; i++) sum[i] = sum[i-1] + g[i];
}

int _, n, m;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		int k = min(n, m), i, j;
		long long ans = 0;
		for(i = 1;i <= k; i = j+1) {
			j = min(m/(m/i), n/(n/i));
			ans += ((long long)(n/i) * (long long)(m/i)) * (sum[j] - sum[i-1]);
		}
		printf("%lld\n", ans);
	}
}