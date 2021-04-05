#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int N = 3e5+7;
const ld PI = acos(-1.0);

struct CP {
	ld x, y;
	CP operator + (const CP &t) const { return {x+t.x, y+t.y}; }
	CP operator - (const CP &t) const { return {x-t.x, y-t.y}; }
	CP operator * (const CP &t) const { return {x*t.x-y*t.y, x*t.y+y*t.x}; }
} f[2][N], g[2][N], ans[3][N];

int rev[N];
void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < n; mid <<= 1) {
		CP Wn = {cos(2*PI/(mid<<1)), flag * sin(2*PI/(mid<<1))};
		for(int i = 0; i < n; i += (mid << 1)) {
			CP W = {1, 0};
			for(int j = 0; j < mid; j++, W = (W * Wn)) {
				CP tmp0 = A[i+j], tmp1 = W * A[i+mid+j];
				A[i+j] = tmp0 + tmp1;
				A[i+mid+j] = tmp0 - tmp1;
			}
		}
	}
}

#define normal(x) (((ll)(x / lim + 0.5)%mod+mod)%mod)
void MTT(int *a, int n, int *b, int m, int mod) {
	int lim = 1, L = 0; while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	for(int i = 0; i < lim; i++) {
		f[0][i].x = a[i] >> 15; f[1][i].x = a[i] & 0x7fff;
		g[0][i].x = b[i] >> 15; g[1][i].x = b[i] & 0x7fff;
	}
	
	FFT(f[0], lim, 1); FFT(f[1], lim, 1);
	FFT(g[0], lim, 1); FFT(g[1], lim, 1);
	
	for(int i = 0; i < lim; i++) {
		ans[0][i] = f[0][i] * g[0][i];
		ans[1][i] = f[0][i] * g[1][i] + f[1][i] * g[0][i];
		ans[2][i] = f[1][i] * g[1][i];
	}
	
	FFT(ans[0], lim, -1); FFT(ans[1], lim, -1); FFT(ans[2], lim, -1);
	
	for(int i = 0; i <= n+m; i++) {
		ll k1 = (normal(ans[0][i].x) << 30) % mod;
		ll k2 = (normal(ans[1][i].x) << 15) % mod;
		ll k3 = normal(ans[2][i].x) % mod;
		printf("%lld ", ((k1+k2)%mod+k3)%mod);
	}
}

int n, m, mod, a[N], b[N];

int main() {
	scanf("%d %d %d", &n, &m, &mod);
	for(int i = 0; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 0; i <= m; i++) scanf("%d", &b[i]);
	MTT(a, n, b, m, mod);
}