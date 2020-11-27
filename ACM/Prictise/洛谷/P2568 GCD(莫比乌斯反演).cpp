#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10], pre[MAX+10], sum[MAX+10];

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
		for(int j = 1; j*prime[i] <= MAX; j++) {
			pre[j*prime[i]] += mu[j];
		}
	}
	
	for(int i = 1;i <= MAX; i++) sum[i] = sum[i-1] + pre[i];
	
}

int n;

int main() {
	Mobius();
	scanf("%d", &n);
	long long ans = 0;
	int i, j;
	for(i = 1;i <= n; i = j+1) {
		j = n / (n / i);
		ans += 1LL*(n/i)*(n/i)*(sum[j]-sum[i-1]);
	}
	printf("%lld\n", ans);
}