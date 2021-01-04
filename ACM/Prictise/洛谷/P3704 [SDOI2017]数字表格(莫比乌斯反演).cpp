#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int _;
long long n, m;
long long f[1000006], g[1000006];

const int MAX = 1e6;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

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
	
	f[0] = 0; f[1] = 1;
	for(int i = 2;i <= 1000000; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;
	
	for(int i = 0;i <= 1000000; i++) g[i] = 1;
	for(int i = 1;i <= 1000000; i++) {
		long long inv = qpow(f[i], mod-2);
		for(int j = i;j <= 1000000; j += i) {
			long long t;
			if(mu[j/i] == 1) t = f[i];
			else if(mu[j/i] == 0) t = 1;
			else t = inv;
			g[j] = (g[j] * t) % mod;
		}
	}
	
	for(int i = 1;i <= 1000000; i++) {
		g[i] = g[i] * g[i-1];
		g[i] %= mod;
	}
}

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &m);
		if(n > m) swap(n, m);
		long long ans = 1;
//		for(int i = 1;i <= n; i++) {
//			ans = (ans * qpow(g[i]*qpow(g[i-1], mod-2)%mod, (n/i)*(m/i))) % mod;
//		}
		
		for(int l = 1, r;l <= n; l = r+1) {
			r = min(n/(n/l), m/(m/l));
			ans = (ans * qpow(g[r]*qpow(g[l-1], mod-2)%mod, (long long)(n/l)*(long long)(m/l))) % mod;
		}
		
		printf("%lld\n", (ans+mod)%mod);
	}
}


// 暴力
//#include <bits/stdc++.h>
//using namespace std;
//const long long mod = 1e9+7;
//long long f[1000006];
//int _, n, m;
//map <int, int> num;
//
//int main() {
//	f[0] = 0; f[1] = 1;
//	for(int i = 2;i <= 1000000; i++)
//		f[i] = (f[i-1] + f[i-2]) % mod;
//	
//	scanf("%d", &_);
//	while (_--) {
//		num.clear();
//		scanf("%d %d", &n, &m);
//		for(int i = 1;i <= n; i++) {
//			for(int j = 1;j <= m; j++) {
//				num[__gcd(i,j)]++;
//			}
//		}
//		
//		long long ans = 1;
//		for(auto i: num) {
//			//			printf("i = %d num = %d\n", i.first, i.second);
//			for(int j = 1;j <= i.second; j++) {
//				ans = (ans * f[i.first]) % mod;
//			}
//		}
//		
//		cout << ans << endl;
//	}
//}