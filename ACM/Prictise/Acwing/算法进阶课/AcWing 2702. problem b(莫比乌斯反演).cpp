#include <bits/stdc++.h>
using namespace std;

int _;
int a, b, c, d, k;

const int MAX = 1e5;
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

long long cal(int x, int y) {
	x /= k; y /= k;
	int mi = min(x, y);
	long long ans = 0;
	for(long long l = 1, r; l <= mi; l = r + 1) {
		r = min(x/(x/l), y/(y/l));
		ans += 1ll*(pre[r]-pre[l-1]) * (x/l) * (y/l);
	}
	return ans;
}

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		printf("%lld\n", cal(b,d)-cal(a-1,d)-cal(b,c-1)+cal(a-1,c-1));
	}
}