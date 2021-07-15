#include<bits/stdc++.h>
using namespace std;

const int N = 400007;
const double pi = acos(-1.0);
int n, m;
int rev[N];
struct CP {
	double x,y;
	CP operator+ (const CP& t) const{ return {x + t.x, y + t.y}; }
	CP operator- (const CP& t) const{ return {x - t.x, y - t.y}; }
	CP operator* (const CP& t) const{ return {x * t.x - y * t.y, x * t.y + y * t.x}; }
} a[N], b[N];

void FFT(CP *A, int n, int flag) {
	for(int i=0;i<n;++i) if(i < rev[i]) swap(A[i],A[rev[i]]);
	for(int mid=1;mid<n;mid<<=1) {
		CP Wn = {cos(2*pi/(mid<<1)) , flag*sin(2*pi/(mid<<1))};
		for(int i=0;i<n;i+=(mid<<1)) {
			CP W = {1 , 0};
			for(int j=0;j<mid;++j,W=(W*Wn)) {
				CP tmp0 = A[i+j], tmp1 = W*A[i+mid+j];
				A[i+j] = tmp0 + tmp1;
				A[i+mid+j] = tmp0 - tmp1;
			}
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i++) scanf("%lf", &a[i].x);
	for(int i = 0; i <= m; i++) scanf("%lf", &b[i].x);
	
	int lim = 1, L = 0; 
	while(lim <= n+m) lim <<= 1, ++L; // lim为最终多项式的最大可能长度，与n有关，根据题目修改
	for(int i = 0;i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	
	for(int i = 0; i <= n+m; i++) {
		printf("%d ", (int)(a[i].x / lim + 0.5));
	}
	puts("");
}