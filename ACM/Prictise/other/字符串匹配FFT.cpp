#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3*3e5+7;
const double PI = acos(-1.0);

int n, m;
int rev[N];
struct CP {
	double x, y;
	CP operator + (const CP &t) const {return {x+t.x, y+t.y};}
	CP operator - (const CP &t) const {return {x-t.x, y-t.y};}
	CP operator * (const CP &t) const {return {x*t.x-y*t.y, x*t.y+y*t.x};}
} a[N], b[N], tmp[N];
void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++)
		if(i < rev[i]) swap(A[i], A[rev[i]]);
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
int p[N], q[N];
ll f[N], T;


int main() {
	scanf("%d %d", &m, &n);
	scanf("%s %s", t, s);
	int lim = 1, L = 0; while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	for(int i = 0; i < n; i++) {
		p[i] = s[i]-'a';
		f[i] = f[i-1] + p[i]*p[i];
	}
	
	for(int i = 0; i < m; i++) {
		q[i] = t[i]-'a';
		T += q[i]*q[i];
	}
	
	for(int i = 0; i < n; i++) a[i] = {1.0*p[i], 0};
	for(int i = 0; i < m; i++) b[i] = {1.0*q[i], 0}, tmp[i] = b[i];
	for(int i = 0; i < m; i++) b[i] = tmp[m-i-1];
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i <= lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	for(int i = 0; i <= lim; i++) a[i].x = (int)(a[i].x/lim+0.5);
	
	int ans = 0;
	for(int i = 0; i <= n-m; i++) {
		if(T + f[i+m-1] - f[i-1] - 2 * (int)(a[m+i-1].x) == 0) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
}