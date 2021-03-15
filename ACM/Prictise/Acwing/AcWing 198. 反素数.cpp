#include <bits/stdc++.h>
using namespace std;

long long n;

const int N = 100;
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

long long qpow(long long x, long long n) {
	long long res = 1; 
	for (; n; n >>= 1, x = x * x)
		if (n & 1) res = res * x;
	return res;
}

vector <int> res, pr;
long long ans = 1e9, anst;

void dfs(int d, int now) {
//	printf("%d %d\n", prime[d], now);
	int t = n / now, num = 0;
	while(t >= prime[d]) {
		t /= prime[d];
		num++;
	}
	
	if(num == 0) {
		int fin = 1;
		int k = 1;
		for(int i: res) fin *= (i+1);
		
		if(fin > anst || (fin == anst && ans > now)) {
			ans = now;
			anst = fin;
//			printf("ans = %lld\n", ans);
		}
		return;
	}
	for(int i = num;i >= 1; i--) {
		res.push_back(i);
		dfs(d+1, now * qpow(prime[d], i));
		res.pop_back();
	}
}

int main() {
	getprime();
	scanf("%lld", &n);
	int num = 0;
	long long now = 1;
	for(int i = 1; i <= 32; i++) {
		now *= 2;
		if(now > n) break;
		num++;
	}
	
	dfs(0, 1);
	
	printf("%lld\n", ans);
}