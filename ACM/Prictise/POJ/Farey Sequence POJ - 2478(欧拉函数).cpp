#include <iostream>
using namespace std;

const int N = 1e6;
int isPrime[N+10], phi[N+10];

void Eular() { // 欧拉函数
	for(int i = 1;i <= N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 0; // 看题目情况决定是否为0
	for(int i = 2;i <= N; i++) {
		if(isPrime[i]) {
			for(int j = i;j <= N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int n;

int main() {
	Eular();
	while(~scanf("%d", &n) && n) {
		long long ans = 0;
		for(int i = 1;i <= n; i++) {
			ans += phi[i];
		}
		printf("%lld\n", ans);
	}
}