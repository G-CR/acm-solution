#include <bits/stdc++.h>
using namespace std;

const int N = 4e4+7;
int isPrime[N], phi[N];

void Eular() { // 欧拉函数
	for(int i = 1;i < N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2;i < N; i++) {
		if(isPrime[i]) {
			for(int j = i;j < N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int n;

int main() {
	Eular();
	scanf("%d", &n);
	if(n == 1) return puts("0"), 0;
	long long ans = 0;
	for(int i = 1;i < n; i++) {
		ans += 1LL * phi[i];
	}
	
	printf("%lld\n", ans * 2 + 1);
}