#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

bool isPrime(int num) {
	if (num <= 3) {
		return num > 1;
	}
	// 不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int t = (int)sqrt(num);
	for (int i = 5; i <= t; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

int n;

int main() {
	getprime();
	scanf("%d", &n);
	int ans = -1;
	for(int i = 2;i*i <= n; i++) {
		if(isprime[i] && n % i == 0) {
			int t = n / i;
			bool ip = 0;
			if(t > 1e7) ip = isPrime(t);
			else ip = isprime[t];
			if(ip) {
				ans = max(ans, max(i, t));
			}
		}
	}
	
	printf("%d\n", ans);
}