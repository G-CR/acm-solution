#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;

const double PI = acos(-1.0);
int rev[3*N];
struct CP {
	double x, y;
	CP operator + (const CP& t) const {return {x+t.x, y+t.y};}
	CP operator - (const CP& t) const {return {x-t.x, y-t.y};}
	CP operator * (const CP& t) const {return {x*t.x-y*t.y, x*t.y+y*t.x}; }
} a[3*N], b[3*N], tmp[3*N];

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

int n, m, k, p[3*N], q[3*N], res[3*N];
char s[N], t[N], c[] = {'A', 'C', 'T', 'G'};

int cg(int pos) {
	int num = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == c[pos]) p[i] = 2;
		else p[i] = 0;
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == c[pos]) q[i] = 1, num++;
		else q[i] = 0;
	}
	
	int la = -1e9;
	for(int i = 0; i < n; i++) {
		if(p[i] == 2) la = i;
		if(la + k >= i) p[i] = max(p[i], 1);
	}
	la = 1e9;
	for(int i = n-1; i >= 0; i--) {
		if(p[i] == 2) la = i;
		if(la - k <= i) p[i] = max(p[i], 1);
	}
	for(int i = 0; i < n; i++) if(p[i]) p[i] = 1;
	
	return num;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s %s", s, t);
	
	int lim = 1, L = 0; while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	for(int pos = 0; pos < 4; pos++) {
		int num = cg(pos);
		for(int i = 0; i < lim; i++) a[i] = {1.0*p[i], 0};
		for(int i = 0; i < lim; i++) b[i] = {1.0*q[i], 0}, tmp[i] = b[i];
		for(int i = 0; i < m; i++) b[i] = tmp[m-1-i];
		
		FFT(a, lim, 1); FFT(b, lim, 1);
		for(int i = 0; i <= lim; i++) a[i] = a[i] * b[i];
		FFT(a, lim, -1);
		for(int i = 0; i <= lim; i++) a[i].x = (int)(a[i].x/lim+0.5);
		
		for(int i = 0; i <= n-m; i++) {
			if(((int)a[m+i-1].x) == num) {
				res[i]++;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= n-m; i++) {
		if(res[i] == 4) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
}