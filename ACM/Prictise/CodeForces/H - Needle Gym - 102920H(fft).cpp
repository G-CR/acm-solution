#include <bits/stdc++.h>
using namespace std;

const int N = 4 * 200005;
const double pi = acos(-1);

int n, m;
int rev[N];
struct CP {
	double x, y;
	CP operator + (const CP &t) const { return {x + t.x, y + t.y}; }
	CP operator - (const CP &t) const { return {x - t.x, y - t.y}; }
	CP operator * (const CP &t) const { return {x * t.x - y * t.y, x * t.y + y * t.x}; }
} a[N], b[N];

void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < n; mid <<= 1) {
		CP Wn = {cos(2*pi/(mid<<1)), flag*sin(2*pi/(mid<<1))};
		for(int i = 0; i < n; i += (mid << 1)) {
			CP W = {1, 0};
			for(int j = 0; j < mid; ++j, W = (W * Wn)) {
				CP tmp0 = A[i+j], tmp1 = W * A[i+mid+j];
				A[i+j] = tmp0 + tmp1;
				A[i+mid+j] = tmp0 - tmp1;
			}
		}
	}
}

int n1, n2, n3;
int p[N], q[N], r[N];

int read(int &n, int *r) {
	int ma = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
		r[i] += 30000;
		ma = max(ma, r[i]);
	}
	return ma;
}

void out(int n, int *r) {
	for(int i = 1; i <= n; i++)
		printf("%d ", r[i]);
	puts("");
}

int main() {
	int ma = 0;
	ma += read(n1, p); read(n2, q); ma += read(n3, r);
	int lim = 1, L = 0; while(lim <= ma) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(L-1));
	for(int i = 1; i <= n1; i++) a[p[i]].x++;
	for(int i = 1; i <= n3; i++) b[r[i]].x++;
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	for(int i = 0; i <= ma; i++)
		a[i].x = (long long)(a[i].x/lim+0.5);
	
	long long ans = 0;
	for(int i = 1; i <= n2; i++) {
		if(2*q[i] > ma) continue;
		ans += a[2*q[i]].x;
	}
	
	printf("%lld\n", ans);
}