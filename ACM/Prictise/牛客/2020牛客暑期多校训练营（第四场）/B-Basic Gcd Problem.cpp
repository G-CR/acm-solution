#include <bits/stdc++.h>
using namespace std;

const int N = 1000000, mod = 1e9+7;
int _, n, c, isnot[N+6];
int gcr[N+6];

void getys(){
	for(int i=2;i <= N;i++){
		if(!isnot[i]) {
			for (int j = i; j <= N; j += i) {
				isnot[j] = true;
				int t = j;
				while(t%i==0) {t /= i; gcr[j]++;}
			}
		}
	}
}

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	getys(); 
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &c);
		printf("%lld\n", qpow(c, gcr[n]));
	}
}