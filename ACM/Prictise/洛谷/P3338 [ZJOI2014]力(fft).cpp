#include<bits/stdc++.h>
using namespace std;

inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x * f;
}

const int N = 400007;
const double pi = acos(-1.0);
int n;
int rev[N];
struct CP {
	double x,y;
	CP operator + (CP el) { return (CP)<%x+el.x , y+el.y%>; }
	CP operator - (CP el) { return (CP)<%x-el.x , y-el.y%>; }
	CP operator * (CP el) { return (CP)<%x*el.x-y*el.y , x*el.y+y*el.x%>; }
} a[N], b[N], c[N];

void FFT(CP *A, int n, int flag) {
	for(int i=0;i<n;++i) if(i < rev[i]) swap(A[i],A[rev[i]]);
	for(int mid=1;mid<n;mid<<=1) {
		CP Wn = (CP)<%cos(2*pi/(mid<<1)) , flag*sin(2*pi/(mid<<1))%>;
		for(int i=0;i<n;i+=(mid<<1)) {
			CP W = (CP)<%1 , 0%>;
			for(int j=0;j<mid;++j,W=(W*Wn)) {
				CP tmp0 = A[i+j], tmp1 = W*A[i+mid+j];
				A[i+j] = tmp0 + tmp1;
				A[i+mid+j] = tmp0 - tmp1;
			}
		}
	}
	if(flag == -1) {
		for(int i=0;i<n;++i) A[i].x /= n;
	}
}


int main() {
	n = read();
	for(int i = 1;i <= n; i++) {
		scanf("%lf", &a[i].x);
		c[n-i].x = a[i].x;
		b[i].x = (double)(1.0/i/i);
	}
	
	int lim = 1, L = 0; while(lim <= (n<<1)) lim <<= 1, ++L; // lim为最终多项式的最大可能长度，与n有关，根据题目修改
	for(int i = 0;i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	FFT(a, lim, 1); FFT(b, lim, 1); FFT(c, lim, 1);
	for(int i = 0;i < lim; i++) a[i] = a[i]*b[i], c[i] = c[i]*b[i];
	FFT(a, lim, -1); FFT(c, lim, -1);
	
	for(int i = 1;i <= n; i++) {
		printf("%.3lf\n", a[i].x-c[n-i].x);
	}
}