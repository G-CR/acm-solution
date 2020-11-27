#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10], pre[MAX+10];
long long g[MAX+10];

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
	
	for(int i = 1;i <= MAX; i++) {
		int l, r;
		for(l = 1;l <= i; l = r+1) {
			r = i / (i / l);
			g[i] += 1ll * (r-l+1) * (i/l);
		}
	}
}

int _, n, m;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		int mi = min(n, m);
		int l, r;
		long long ans = 0;
		for(l = 1;l <= mi; l = r+1) {
			r = min(n/(n/l), m/(m/l));
			ans += (pre[r]-pre[l-1]) * g[n/l] * g[m/l];
		}
		printf("%lld\n", ans);
	}
}