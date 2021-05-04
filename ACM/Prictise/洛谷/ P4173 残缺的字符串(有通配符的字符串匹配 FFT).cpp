#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4 * 3e5 + 7;
const double PI = acos(-1.0);

int n, m;
int rev[N];
struct CP {
	double x, y;
	CP operator + (const CP &t) const {return {x+t.x, y+t.y};}
	CP operator - (const CP &t) const {return {x-t.x, y-t.y};}
	CP operator * (const CP &t) const {return {x*t.x-y*t.y, x*t.y+y*t.x};}
} a[N], A[N], b[N], B[N], f[N];

void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < n; mid <<= 1) {
		CP Wn = {cos(2*PI/(mid<<1)), flag*sin(2*PI/(mid<<1))};
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

char s[N], t[N];
ll p[N], q[N];

int main() {
	scanf("%d %d", &m, &n);
	scanf("%s %s", t, s);
	int lim = 1, L = 0; while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	for(int i = 0; i < n; i++) {
		if(s[i] == '*') p[i] = 0;
		else p[i] = s[i] - 'a' + 1;
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == '*') q[i] = 0;
		else q[i] = t[i] - 'a' + 1;
	}
	
	for(int i = 0; i < n; i++) a[i] = {1.0*p[i], 0};
	for(int i = 0; i < m; i++) b[i] = {1.0*q[i], 0};
	reverse(b, b+m);
	
	for(int i = 0; i < lim; i++) A[i] = a[i] * a[i] * a[i];
	for(int i = 0; i < lim; i++) B[i] = b[i];
	FFT(A, lim, 1); FFT(B, lim, 1);
	for(int i = 0; i < lim; i++) f[i] = f[i] + A[i]*B[i];
	
	for(int i = 0; i < lim; i++) A[i] = a[i];
	for(int i = 0; i < lim; i++) B[i] = b[i] * b[i] * b[i];
	FFT(A, lim, 1); FFT(B, lim, 1);
	for(int i = 0; i < lim; i++) f[i] = f[i] + A[i]*B[i];
	
	CP two = {2, 0};
	for(int i = 0; i < lim; i++) A[i] = a[i] * a[i];
	for(int i = 0; i < lim; i++) B[i] = b[i] * b[i];
	FFT(A, lim, 1); FFT(B, lim, 1);
	for(int i = 0; i < lim; i++) f[i] = f[i] - two * A[i]*B[i];
	
	FFT(f, lim, -1);
	for(int i = 0; i <= n+m; i++) f[i].x = (int)(f[i].x/lim+0.5);
	
	vector <int> res;
	for(int i = 0; i <= n-m; i++) {
		if((int)f[m+i-1].x == 0) {
			res.push_back(i+1);
		}
	}
	
	printf("%lu\n", res.size());
	for(int i : res) printf("%d ", i);
	puts("");
}