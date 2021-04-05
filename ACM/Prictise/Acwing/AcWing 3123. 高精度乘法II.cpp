#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
const double pi = acos(-1);
int n, m;
int rev[N];

struct CP {
	double x, y;
	CP operator+ (const CP& t) const {return {x + t.x, y + t.y}; }
	CP operator- (const CP& t) const {return {x - t.x, y - t.y}; }
	CP operator* (const CP& t) const {return {x*t.x - y*t.y, x*t.y + y*t.x}; }
} a[N], b[N];

void FFT(CP *A, int n, int flag) {
	for(int i = 0; i < n; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid = 1; mid < n; mid <<= 1) {
		CP Wn = {cos(2*pi / (mid<<1)), flag*sin(2*pi/(mid<<1))};
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

string s, t;

void input() {
	cin >> s >> t;
	n = s.length(); m = t.length();
	for(int i = 0; i < n; i++) a[i].x = s[i] - '0';
	for(int i = 0; i < m; i++) b[i].x = t[i] - '0';
}

void output() {
	for(int i = 0; i < n; i++) printf("%d", (int)a[i].x); puts("");
	for(int i = 0; i < m; i++) printf("%d", (int)b[i].x); puts("");
}

int main() {
	input();
	int lim = 1, L = 0;
	while(lim <= n+m) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	
	
	for(int i = 0; i <= n+m-2; i++) {
		a[i].x = a[i].x / lim;
	}
	
	int jin = 0;
	vector <int> ans;
	for(int i = n+m-2; i >= 0; i--) {
		int now = (a[i].x+0.5) + jin;
		ans.push_back(now % 10);
		jin = now / 10;
	}
	
	while(jin) {
		ans.push_back(jin%10);
		jin /= 10;
	}
	
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) printf("%d", ans[i]);
	
	puts("");
	return 0;
}