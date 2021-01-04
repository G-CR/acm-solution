#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;

const double pi = acos(-1.0);
int rev[MAXN];
struct CP {
	double x,y;
	CP operator + (CP el) { return (CP)<%x+el.x , y+el.y%>; }
	CP operator - (CP el) { return (CP)<%x-el.x , y-el.y%>; }
	CP operator * (CP el) { return (CP)<%x*el.x-y*el.y , x*el.y+y*el.x%>; }
} x[MAXN];

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

int _, n;
long long a[MAXN], num[MAXN], sum[MAXN];

int main() {
	scanf("%d", &_);
	while(_--) {
		for(int i = 0;i <= 2e5; i++) num[i] = 0, sum[i] = 0;
		scanf("%d", &n);
		for(int i = 0;i < n; i++) {
			scanf("%lld", &a[i]);
			num[a[i]]++;
		}
		sort(a, a+n);
		int N = a[n-1];
		int lim = 1, L = 0; while(lim <= (N<<1)) lim <<= 1, ++L;
		for(int i = 0;i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
		
		for(int i = 0;i <= N; i++) x[i].x = num[i], x[i].y = 0;
		for(int i = N+1;i < lim; i++) x[i].x = 0, x[i].y = 0;
		
		FFT(x, lim, 1);
		for(int i = 0;i < lim; i++) x[i] = x[i] * x[i];
		FFT(x, lim, -1);
		
		for(int i = 0;i < lim; i++) num[i] = (long long)(x[i].x + 0.5);
		
		lim = 2*a[n-1];
		
		for(int i = 0;i < n; i++) num[a[i]+a[i]]--;
		for(int i = 1;i <= lim; i++) num[i] /= 2;
		for(int i = 1;i <= lim; i++) sum[i] = sum[i-1] + num[i];
		long long cnt = 0;
		for(int i = 0;i < n; i++) {
			cnt += sum[lim]-sum[a[i]];
			cnt -= 1ll*(n-1-i)*i;
			cnt -= n-1;
			cnt -= 1ll*(n-1-i)*(n-2-i)/2;
		}
		
		long long tot = 1ll*n*(n-1)*(n-2)/6;
		printf("%.7lf\n", (double)cnt/tot);
	}
}