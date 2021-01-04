#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e6 + 10, P = 998244353, G = 3, Gi = 332748118;

string s;
int cnta, cntb;
int limit = 1, L, rev[MAXN];
long long a[MAXN], b[MAXN];

int cs(long long *A) {
	for(int i = 0;i < s.length(); i++) A[i] = s[i]-'0';
	return (int)s.length();
}

inline long long fastpow(long long a, long long k) {
	long long base = 1;
	while(k) {
		if(k & 1) base = (base * a ) % P;
		a = (a * a) % P;
		k >>= 1;
	}
	return base % P;
}

inline void NTT(long long *A, int type) {
	for(int i = 0; i < limit; i++) 
		if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < limit; mid <<= 1) {
		long long Wn = fastpow( type == 1 ? G : Gi, (P - 1) / (mid << 1));
		for(int j = 0; j < limit; j += (mid << 1)) {
			long long w = 1;
			for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
				int x = A[j + k], y = w * A[j + k + mid] % P;
				A[j + k] = (x + y) % P,
				A[j + k + mid] = (x - y + P) % P;
			}
		}
	}
}

int main() {
	cin >> s; cnta = cs(a);
	cin >> s; cntb = cs(b);
	
	while(limit <= cnta + cntb) limit <<= 1, L++;
	for(int i = 0; i < limit; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	
	NTT(a, 1); NTT(b, 1);
	for(int i = 0;i < limit; i++) a[i] = (a[i]*b[i]) % P;
	NTT(a, -1);
	long long inv = fastpow(limit, P-2);
	
	for(int i = 0;i <= cnta+cntb; i++) a[i] = (a[i]*inv)%P;
	for(int i = 0;i <= cnta+cntb; i++) printf("%lld ", a[i]); puts("");
	vector <int> res;
	int jin = 0;
	for(int i = cnta+cntb-2; i >= 0; i--) {
		int now = a[i];
		now += jin;
		jin = now/10;
		now %= 10;
		res.push_back(now);
	}
	while(jin) {
		res.push_back(jin%10);
		jin /= 10;
	}
	
	reverse(res.begin(), res.end());
	for(int i: res) printf("%d", i);
}