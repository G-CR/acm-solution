#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long p, a[5000006], pre[5000006], beh[5000006];

int read() {
	int x=0,flag=1;char c;
	while((c=getchar())<'0' || c>'9') if(c=='-') flag=-1;
	while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*flag;
}

int qmod(long long k) {
	return k - (k/p)*p;
}

long long qpow(long long x, long long n) {
	long long res = 1;
	for(; n; n >>= 1, x = qmod(x * x))
		if(n & 1) res = qmod(res * x);
	return res;
}

int main() {
	n = read(); p = read(); k = read();
	pre[0] = 1; beh[n+1] = 1;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		pre[i] = qmod(pre[i-1] * a[i]);
	}
	for(int i = n; i >= 1; i--) beh[i] = qmod(beh[i+1] * a[i]);
	
	long long inv = qpow(pre[n], p-2);
	
	long long fk = k, ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = qmod(ans + qmod(fk * (qmod(pre[i-1] * beh[i+1]))));
		fk = qmod(fk * k);
	}
	
	printf("%d\n", qmod(ans * inv));
}