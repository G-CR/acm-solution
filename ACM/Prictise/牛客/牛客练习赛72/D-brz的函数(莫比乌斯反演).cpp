#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10];
int pre[MAX+10], ans[MAX+10];

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
		int res = 0;
		for(int l = i, r; l <= MAX; l = r+1) {
			r = min(MAX, l+i-1);
			res += mu[l];
			ans[l] += mu[i] * res * res;
			ans[r+1] += -mu[i] * res * res;
		}
	}
	
	for(int i = 1;i <= MAX; i++) {
		ans[i] = ans[i-1] + ans[i];
	}
}

int _, n;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
}