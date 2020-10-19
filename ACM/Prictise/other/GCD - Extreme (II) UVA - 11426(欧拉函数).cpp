#include <bits/stdc++.h>
const int N = 4000006;
using namespace std;

int n;
long long phi[N], isPrime[N];
void Eular() {
	for(int i = 1;i < N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 0;
	for(int i = 2;i < N; i++) {
		if(isPrime[i]) {
			for(int j = i;j < N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}

long long f[N], ans[N];

int main() {
	Eular();
	for(int i = 1;i < N; i++) {
		for(int j = i*2;j < N; j += i) {
			f[j] += i*phi[j/i];
		}
	}
	
	for(int i = 1;i < N; i++) {
		ans[i] = ans[i-1] + f[i];
	}
		
	while(~scanf("%d", &n) && n) {
		printf("%lld\n", ans[n]);
	}
}