#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
const int N = 4 * 100005;

int n, m, ans[N];
char s[N], t[N];
int rev[N];
struct CP {
	double x, y;
	CP operator + (const CP &t) const { return {x + t.x, y + t.y}; }
	CP operator - (const CP &t) const { return {x - t.x, y - t.y}; }
	CP operator * (const CP &t) const { return {x*t.x - y*t.y, x*t.y + y*t.x}; }
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

int lim = 1, L = 0;

void solve(char k) {
	for(int i = 0; i < n; i++) {
		if(s[i] == k) a[i].x = 1;
		else a[i].x = 0;
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == k) b[i].x = 1;
		else b[i].x = 0;
	}
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	for(int i = 0; i <= n+m; i++) a[i].x = (int)(a[i].x/lim+0.5);
	
	for(int i = 0; i <= n+m; i++) ans[i] += a[i].x;
	
	for(int i = 0; i <= lim; i++) {
		a[i].x = a[i].y = 0;
		b[i].x = b[i].y = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s %s", s, t);
	for(int i = 0; i < m; i++) {
		if(t[i] == 'R') t[i] = 'S';
		else if(t[i] == 'S') t[i] = 'P';
		else t[i] = 'R';
	}
	reverse(t, t+m);
	
	while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	solve('R'); solve('S'); solve('P');
	
	int res = 0;
	for(int i = m-1; i < n+m; i++) {
		res = max(res, ans[i]);
	}
	
	printf("%d\n", res);
}