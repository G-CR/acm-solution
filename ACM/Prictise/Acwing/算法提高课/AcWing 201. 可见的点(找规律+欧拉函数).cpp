#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int isPrime[N+10], phi[N+10];

void Eular() { // 欧拉函数
	for(int i = 1;i <= N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 1; // 看题目情况决定是否为0
	for(int i = 2;i <= N; i++) {
		if(isPrime[i]) {
			for(int j = i;j <= N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int _, n;

int main() {
	Eular();
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += phi[i];
		printf("%d %d %d\n", ++cas, n, sum*2+1);
	}
}