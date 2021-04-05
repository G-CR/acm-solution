#include <bits/stdc++.h>
using namespace std;
const int N = 100004;
const double PI = acos(-1.0);
int n, minn, sz[N], mx[N], vis[N], rt, cnt[N];
vector <int> g[N];

const int M = 1e7;
int isprime[M+10], prime[M+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2;i < M;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < M;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

int rev[N];
struct CP {
	double x,y;
	CP operator+ (const CP& t) const{ return {x + t.x, y + t.y}; }
	CP operator- (const CP& t) const{ return {x - t.x, y - t.y}; }
	CP operator* (const CP& t) const{ return {x * t.x - y * t.y, x * t.y + y * t.x}; }
} a[N], b[N];

void FFT(CP *A, int n, int flag) {
	for(int i=0;i<n;++i) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(int mid=1;mid<n;mid<<=1) {
		CP Wn = {cos(2*PI/(mid<<1)) , flag*sin(2*PI/(mid<<1))};
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

void get_rt(int u, int f) {
	sz[u] = 1; mx[u] = 0;
	for(int i: g[u]) {
		int to = i;
		if(vis[to] || to == f) continue;
		get_rt(to, u);
		sz[u] += sz[to];
		mx[u] = max(mx[u], sz[to]);
	}
	
	mx[u] = max(mx[u], n - sz[u]);
	if(minn > mx[u]) {
		minn = mx[u];
		rt = u;
	}
}

vector <int> all, cat;

void cal() {
	int p = 0, q = 0;
	for(int i: all) {
		a[i].x++; p = max(p, i);
	}
	for(int i: cat) {
		b[i].x++; q = max(q, i);
	}
	
	int lim = 1, L = 0;
	while(lim <= p + q) lim <<= 1, ++L;
	for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
	FFT(a, lim, 1); FFT(b, lim, 1);
	for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
	FFT(a, lim, -1);
	
	for(int i = 0; i <= p+q; i++) {
		int now = (int)(a[i].x / lim + 0.5);
		cnt[i] += now;
	}
	
	for(int i: cat) {
		cnt[i]++;
		all.push_back(i);
	}
	
	for(int i = 0; i < lim; i++) {
		a[i].x = 0; a[i].y = 0;
		b[i].x = 0; b[i].y = 0;
	}
}

void dfs(int u, int f, int deep) {
	cat.push_back(deep);
	for(int to: g[u]) {
		if(to == f || vis[to]) continue;
		dfs(to, u, deep + 1);
	}
}

void work(int u) {
	all.clear();
	for(int to: g[u]) {
		if(vis[to]) continue;
		cat.clear();
		dfs(to, u, 1);
		cal();
	}
}

void solve(int u) {
	vis[u] = 1;
	work(u);
	
	for(int to : g[u]) {
		if(vis[to]) continue;
		n = sz[u];
		minn = n + 1;
		get_rt(to, 0);
		get_rt(rt, 0);
		
		solve(rt);
	}
}

int main() {
	getprime();
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	minn = n + 1;
	get_rt(1, 0);
	get_rt(rt, 0);
	
	solve(rt);
	
	long long sum = 0, ans = 0;
	for(int i = 1; i <= 1e5; i++) {
		sum += cnt[i];
		if(isprime[i]) {
			ans += cnt[i];
		}
	}
	
	printf("%.8f\n", 1.0*ans/sum);
}