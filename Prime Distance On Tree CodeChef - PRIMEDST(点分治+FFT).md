[题目链接](https://www.codechef.com/problems/PRIMEDST)

题意：输出一棵树上所有的路径长度为素数的链的个数

思路：树上的路径问题比较容易想到的是用点分治来解决。

1、找到树的重心（重心就是最大子树最小的节点）

2、从重心开始遍历子树

3、将当前子树所有节点距离重心的长度暂时保存起来

4、将暂时保存的路径长度 与 之前的所有路径长度进行一一匹配得到当前子树对于答案的一部分贡献

5、另一部分贡献是与重心之间的距离

6、将暂时保存的路径加入所有的路径长度

7、遍历下一个子树回到步骤2，知道重心的所有子树遍历完成

8、将重心下沉到所有子树中去，回到步骤1

9、最后就可以得到所有的长度的个数，素数筛一遍之后用素数答案除以总答案就可以了

以这样的步骤就可以得到所有的路径的情况，但是在路径之间一一匹配的时候考虑到复杂度是 $O(n^2)$ 的，这个步骤需要优化一下。

于是就可以想到用多项式乘法来表示匹配过程，用参数的指数表示路径长度，系数相乘代表情况之间的匹配，这样指数就会相加。这个过程用FFT来做的话复杂度可以降低到 $nlogn$ ，这样这个题理论就可以做了。

然后需要注意的就是多项式数组的清空。

上代码

```cpp
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
```



