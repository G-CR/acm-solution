#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+7;
const double PI = acos(-1);

struct CP {
	double x, y;
	CP operator + (const CP& t) const { return {x+t.x, y+t.y}; }
	CP operator - (const CP& t) const { return {x-t.x, y-t.y}; }
	CP operator * (const CP& t) const { return {x*t.x-y*t.y, x*t.y+y*t.x}; }
} a[N], b[N];

int rev[N];
void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < n; mid <<= 1) {
		CP Wn = {cos(2*PI/(mid<<1)), flag * sin(2*PI/(mid<<1))};
		for(int i = 0; i < n; i += (mid<<1)) {
			CP W = {1, 0};
			for(int j = 0; j < mid; j++, W = W * Wn) {
				CP tmp0 = A[i+j], tmp1 = W * A[i+mid+j];
				A[i+j] = tmp0 + tmp1;
				A[i+mid+j] = tmp0 - tmp1;
			}
		}
	}
}

int n, m;
int ans = 1e9, t, res;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &a[i].x);
		res += a[i].x * a[i].x;
		t += a[i].x;
		a[n+i].x = a[i].x;
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &b[i].x);
		res += b[i].x * b[i].x;
		t -= b[i].x;
	}
	reverse(b, b+n);
	
	int lim = 1, L = 0; while(lim <= n*3) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	
	int now = -1e9;
	for(int i = 0; i < n; i++) {
		now = max(now, 2*(int)(a[i+n].x/lim+0.5));
	}
	
	for(int i = -m; i <= m; i++) {
		ans = min(ans, res + i*i*n + 2*i*t - now);
	}
	
	printf("%d\n", ans);
}