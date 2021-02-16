## 数学

### 素数筛

```cpp
const int N = 1e6;
int isPrime[N+10], phi[N+10];

void Eular() { // 欧拉函数
	for(int i = 1;i <= N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 0; // 看题目情况决定是否为0
	for(int i = 2;i <= N; i++) {
		if(isPrime[i]) {
			for(int j = i;j <= N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}


long long phi(long long n) { // 求单个值的欧拉函数
	long long ans = n ;
	for(long long i = 2 ; i*i<=n ; i++ ) {
		if(!(n%i)){
			ans = ans/i*(i-1) ;
			while(n%i == 0 ){
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}
```



### 唯一分解定理

```cpp
const int M = 1000000;
bool isprime[M+5];
int prime[M+5], cnt;

void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) prime[++cnt] = i;
	}
}

long long getfac(long long x) {
	long long ans=1;
	for(int i = 1;i <= cnt && prime[i] <= x; i++) {
		long long sum = 0;//当前质因数的幂指数
		while(x%prime[i] == 0) { //当是这个数的因子时
			sum++;
			x /= prime[i];
		}
		ans *= (sum+1);//应用定理的结论
	}
	if(x>1) ans *= 2;//当搜索不到的时候，如果这个数最后大于一，那么这个最后结果肯定是素数，并且指数是1
	return ans;
}
```

### 快速幂

```cpp
const long long mod = 1e9+7;
long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}
```



### 最小质因子

```cpp
const int LIM = 3e7 + 10;
int prime[LIM / 3];
int miniFactor[LIM];
int primepos;

void euler() {
	int tmp;
	for (int i = 2; i < LIM; i++) {
		if (!miniFactor[i]) prime[primepos++] = i, miniFactor[i] = i;
		for (int j = 0; (tmp = i * prime[j]) < LIM; j++) {
			miniFactor[tmp] = prime[j];
			if (!(i % prime[j])) break;
		}
	}
}
```



### 莫比乌斯函数

```cpp
const int MAX = 1e7;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10];

void Mobius() {
	memset(check,false,sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i = 2; i <= MAX; i++) {
		if( !check[i] ) {
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < tot; j++) {
			if(i * prime[j] > MAX) break;
			check[i * prime[j]] = true;
			if( i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}
```



### 求逆元

```cpp
long long inv(long long a, long long b){  // b为模数 传参-2
	long long res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;  
	return res;
}
```



### 欧拉函数

```cpp
const int N = 1e6;
int isPrime[N+10], phi[N+10];

void Eular() { // 欧拉函数
	for(int i = 1;i <= N; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 0; // 看题目情况决定是否为0
	for(int i = 2;i <= N; i++) {
		if(isPrime[i]) {
			for(int j = i;j <= N; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}


long long phi(long long n) { // 求单个值的欧拉函数
	long long ans = n ;
	for(long long i = 2 ; i*i<=n ; i++ ) {
		if(!(n%i)){
			ans = ans/i*(i-1) ;
			while(n%i == 0 ){
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}
```

### 组合数

```cpp
const long long mod = 1e9+7;
long long fac[2000006]; // 阶乘表

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long inv(long long a) { // 返回逆元 费马小定理
	return qpow(a, mod-2)%mod;
}

void solve() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i < 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod);
}



// x较大的时候
long long c(long long n, long long r) {
	if(n < r) return 0;
	if(n-r < r) r = n-r;
	long long a = 1,b = 1;
	for(int i = 0; i < r; i++)
		a = (a*(n-i))%mod, b = (b*(i+1))%mod;
	return a*qpow(b, mod-2)%mod;
}
```

### 扩展GCD

```cpp
long long Exgcd(long long a,long long b,long long &x,long long &y) {
	if(!b) {x = 1,y = 0; return a;}
	long long gcd = Exgcd(b,a%b,x,y),tmp=x;
	x = y,y = tmp-a/b*y;
	return gcd;
}
```



### 整除分块

```cpp
long long ans = 0;
for(int i = 1,r = 0;i <= n; i = r+1) {
    if(n/i == 0) break;
    r = n/(n/i);
    ans += (r-i+1)*(n/i);0
}
```



### 进制转换

```cpp
//将为radix进制的s转换成10进制
long long trans(string s,int radix) {
	long long res = 0;
	for(int i = 0;i < s.length(); i++) {
		char t = s[i];
		if(t >= '0' && t <= '9') {
			if(t - '0' >= radix) return -1;
			res = res * radix + 1ll * (t-'0');
		}
		else {
			if(1ll * (t - 'A' + 10) >= radix) return -1;
			res = res * radix + 1ll * (t - 'A' + 10);
		}
	}
	return res;
}
```

### BSGS

```cpp
// 模数为质数
#include <bits/stdc++.h>
using namespace std;

long long a, p, b;

long long bsgs() {
	if(1 % p == b % p) return 0;
	unordered_map<int, int> mp;
	int k = sqrt(p) + 1;
	for(long long i = 0, j = b % p;i <= k-1; i++, j = (j * a) % p) mp[j] = i;
	
	long long ak = 1;
	for(int i = 1;i <= k; i++) ak = ak * a % p;
	
	for(long long i = 1, j = ak; i <= k; i++) {
		if(mp.count(j)) return i*k-mp[j];
		j = (j * ak) % p;
	}
	return -1;
}

int main() {
	while(~scanf("%lld %lld %lld", &a, &p, &b) && a) {
		long long res = bsgs();
		if(res == -1) puts("No Solution");
		else printf("%lld\n", res);
	}
}


// 扩展BSGS (模数不为质数)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e8;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int bsgs(int a, int b, int p) {
    if(1 % p == b % p) return 0;
    int k = sqrt(p) + 1;
    unordered_map<int, int> mp;
    for(int i = 0, j = b % p; i < k; i++, j = (ll)j * a % p) mp[j] = i;
    
    int ak = 1;
    for(int i = 1;i <= k; i++) ak = (ll)ak * a % p;
    
    for(int i = 1, j = ak;i <= k; i++,j = (ll)j * ak % p) {
        if(mp.count(j)) return k * i - mp[j];
        
    }
    return -inf;
}

int exbsgs(int a, int b, int p) {
    b = (b % p + p) % p;
    if(1 % p == b % p) return 0;
    int x, y;
    int d = exgcd(a, p, x, y);
    if(d > 1) {
        if(b % d) return -inf;
        exgcd(a/d, p/d, x, y);
        return exbsgs(a, (ll)b / d * x % (p/d), p/d) + 1;
    }
    return bsgs(a, b, p);
}

int main() {
    int a, p, b;
    while(~scanf("%d %d %d", &a, &p, &b) && a) {
        int res = exbsgs(a, b, p);
        if(res < 0) puts("No Solution");
        else printf("%d\n", res);
    }
    return 0;
}
```



### 1~1e11的素数个数(Min_25筛)

```cpp
#include <bits/stdc++.h>
#define long long 
using namespace std;
long long f[340000], g[340000],n;
void init() {
	long long i,j,m;
	for(m = 1; m*m <= n; ++m) f[m] = n / m-1;
	for(i = 1;i <= m; ++i) g[i] = i-1;
	for(i = 2;i <= m; ++i) {
		if(g[i] == g[i-1]) continue;
		for(j = 1; j <= min(m-1,n/i/i); ++j){
			if(i*j<m) f[j] -= f[i*j]-g[i-1];
			else f[j] -= g[n/i/j]-g[i-1];
		}
		for(j = m;j >= i*i; --j) g[j] -= g[j/i] - g[i-1];
	}
}

int main() {
	scanf("%lld",&n);
	init();
	cout<<f[1]<<endl;
}

// 新版更快 可以到1e12
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
const int N = 5e6 + 2;
bool np[N];
int prime[N], pi[N];
int getprime() {
	int cnt = 0;
	np[0] = np[1] = true;
	pi[0] = pi[1] = 0;
	for(int i = 2; i < N; ++i) {
		if(!np[i]) prime[++cnt] = i;
		pi[i] = cnt;
		for(int j = 1; j <= cnt && i * prime[j] < N; ++j) {
			np[i * prime[j]] = true;
			if(i % prime[j] == 0)   break;
		}
	}
	return cnt;
}
const int M = 7;
const int PM = 2 * 3 * 5 * 7 * 11 * 13 * 17;
int phi[PM + 1][M + 1], sz[M + 1];
void init() {
	getprime();
	sz[0] = 1;
	for(int i = 0; i <= PM; ++i)  phi[i][0] = i;
	for(int i = 1; i <= M; ++i) {
		sz[i] = prime[i] * sz[i - 1];
		for(int j = 1; j <= PM; ++j) phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
	}
}
int sqrt2(LL x) {
	LL r = (LL)sqrt(x - 0.1);
	while(r * r <= x)   ++r;
	return int(r - 1);
}
int sqrt3(LL x) {
	LL r = (LL)cbrt(x - 0.1);
	while(r * r * r <= x)   ++r;
	return int(r - 1);
}
LL getphi(LL x, int s) {
	if(s == 0)  return x;
	if(s <= M)  return phi[x % sz[s]][s] + (x / sz[s]) * phi[sz[s]][s];
	if(x <= prime[s]*prime[s])   return pi[x] - s + 1;
	if(x <= prime[s]*prime[s]*prime[s] && x < N) {
		int s2x = pi[sqrt2(x)];
		LL ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
		for(int i = s + 1; i <= s2x; ++i) ans += pi[x / prime[i]];
		return ans;
	}
	return getphi(x, s - 1) - getphi(x / prime[s], s - 1);
}
LL getpi(LL x) {
	if(x < N)   return pi[x];
	LL ans = getphi(x, pi[sqrt3(x)]) + pi[sqrt3(x)] - 1;
	for(int i = pi[sqrt3(x)] + 1, ed = pi[sqrt2(x)]; i <= ed; ++i) ans -= getpi(x / prime[i]) - i + 1;
	return ans;
}
LL lehmer_pi(LL x) {
	if(x < N)   return pi[x];
	int a = (int)lehmer_pi(sqrt2(sqrt2(x)));
	int b = (int)lehmer_pi(sqrt2(x));
	int c = (int)lehmer_pi(sqrt3(x));
	LL sum = getphi(x, a) +(LL)(b + a - 2) * (b - a + 1) / 2;
	for (int i = a + 1; i <= b; i++) {
		LL w = x / prime[i];
		sum -= lehmer_pi(w);
		if (i > c) continue;
		LL lim = lehmer_pi(sqrt2(w));
		for (int j = i; j <= lim; j++) sum -= lehmer_pi(w / prime[j]) - (j - 1);
	}
	return sum;
}
int main() {
	init();
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",lehmer_pi(n));
	return 0;
}
```





## 计算几何

### 点相关

```cpp
const double PI = acos(-1.0);
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point { // 表示点
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
};

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

// 三个点计算叉积 p0p1 ^ p0p2
double xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}
```

### 线相关

```cpp
struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	// 判断直线相交的，无需要可以不用（如果相交返回交点的版本，下面有一个只做判断的版本）
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator &(const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0,res);//两直线重合
			else return make_pair(1,res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2,res);//有交点
	}
	
	
	//线段与线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
				(d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
				(d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
				(d4==0 &&sgn((e-v.s)*(e-v.e))<=0);
	}
	
	// 点和直线的关系
	// 1 在左侧
	// 2 在右侧
	// 3 在直线上
	int relation(Point p){
		int c=sgn((p-s)^(p-e));
		if(c<0)return 1;
		else if(c>0) return 2;
		else return 3;
	}
	
	// 两向量平行 (对应直线平行或重合)
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
	//直线与直线相交判断
	//0 平行
	//1 重合
	//2 相交
	int line_cross_line(Line v){
		if((*this).parallel(v))
		return v.relation(s)==3;
		return 2;
	}
};

//*判断线段相交
bool inter(Line l1,Line l2) {
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

// 判断直线l1和线段l2是否相交
bool Seg_inter_line(Line l1, Line l2) { 
	return sgn(xmult(l2.s,l1.s,l1.e))*sgn(xmult(l2.e,l1.s,l1.e)) <= 0;
}

// 点P在直线AB上的投影
Point GetLineProjection(Point P,Point A,Point B) {
	Point v = B - A;
	double t = (v * (P-A)) / (v*v);
	return A + Point(v.x*t, v.y*t);
}


//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg(Point P,Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1) {
		result.x = L.s.x + (L.e.x - L.s.x)*t;
		result.y = L.s.y + (L.e.y - L.s.y)*t;
	}
	else {
		if(dist(P,L.s) < dist(P,L.e))
			result = L.s;
		else result = L.e;
	}
	return result;
}

//*判断点在线段上
bool OnSeg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
```

### 圆相关

```cpp
Point center(Point a, Point b, Point c) { // 三点共圆圆心公式
	double X, Y;
	double fm1=2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
	double fm2=2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);
	if (fm1 == 0 || fm2 == 0) {
		X = Y = 1e18;
		return Point(X, Y);
	}
	double fz1=a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
	double fz2=a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
	X = (fz1 * (a.y - c.y) - fz2 * (a.y - b.y)) / fm1;
	Y = (fz1 * (a.x - c.x) - fz2 * (a.x - b.x)) / fm2;
	
	return Point(X, Y);
}
```



### 凸包相关

```cpp
const int N = 10004;
Point poly[N];
int sta[N], top;
//利用极角排序，角度相同则距离小排前面
bool cmp(Point p1, Point p2) {
	double tmp = xmult(poly[0], p1, p2);
	if (tmp > 0)
		return true;
	else if (tmp == 0 && dist(poly[0], p1) < dist(poly[0], p2))
		return true;
	else
		return false;
}

//输入，并把  最左下方的点放在 poly[0] , 并且进行极角排序
void init(int n) {
	int i, k = 0;
	cin >> poly[0].x >> poly[0].y;
	Point p0 = poly[0];  // p0 等价于 tmp 去寻找最左下方的点
	for (int i = 1; i < n; ++i) {
		cin >> poly[i].x >> poly[i].y;
		if (p0.y > poly[i].y || (p0.y == poly[i].y && p0.x > poly[i].x))
			p0 = poly[i], k = i;
	}
	poly[k] = poly[0];
	poly[0] = p0;
	sort(poly + 1, poly + n, cmp);
}

//graham扫描法求凸包，凸包顶点存在sta栈中
//从栈底到栈顶一次是逆时针方向排列的
//如果要求凸包的一条边有2个以上的点
//那么要将while中的<=改成<
//但这不能将最后一条边上的多个点保留
//因为排序时将距离近的点排在前面
//那么最后一条边上的点仅有距离最远的会被保留，其余的会被出栈
//所以最后一条边需要特判
//如果要求逆凸包的话需要改cmp，graham中的符号即可
void Graham(int n) {
	if (n == 1) top = 0, sta[0] = 0;
	if (n == 2) top = 1, sta[0] = 0, sta[1] = 1;
	if (n > 2) {
		for (int i = 0; i <= 1; i++) sta[i] = i;
		top = 1;
		
		for (int i = 2; i < n; i++) {
			while (top > 0 && xmult(poly[sta[top - 1]], poly[sta[top]], poly[i]) <= 0)
				top--;
			top++;
			sta[top] = i;
		}
	}
}

// ---------------- 以上求凸包 --------------------


//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool isconvex(Point poly[],int n) {
	bool s[3];
	memset(s,false,sizeof(s));
	for(int i = 0;i < n;i++) {
		s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
		if(s[0] && s[2])return false;
	}
	return true;
}

//*判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly(Point a,Point p[],int n) {
	for(int i = 0;i < n;i++) {
		if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
		else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
	}
	return 1;
}

//*判断点在任意多边形内
//射线法，poly[]的顶点数要大于等于3,点的编号0~n-1
//返回值
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inPoly(Point p,Point poly[],int n) {
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0;//-INF,注意取值防止越界

	for(int i = 0;i < n;i++) {
		side.s = poly[i];
		side.e = poly[(i+1)%n];

		if(OnSeg(p,side))return 0;

		//如果平行轴则不考虑
		if(sgn(side.s.y - side.e.y) == 0)
			continue;

		if(OnSeg(side.s,ray)) {
			if(sgn(side.s.y - side.e.y) > 0)cnt++;
		}
		else if(OnSeg(side.e,ray)) {
			if(sgn(side.e.y - side.s.y) > 0)cnt++;
		}
		else if(inter(ray,side)) cnt++;
	}
	if(cnt % 2 == 1) return 1;
	else return -1;
}

// 多边形面积(点坐标顺时针给出,逆时针为负数)
double PolygonArea(Point *p,int n) {
	double area=0;
	for(int i = 1;i < n-1; i++)
		area += (p[i]-p[0])^(p[i+1]-p[0]);
	return area/2;
}
```

### 三角形相关

```cpp
// 三角形求垂心、重心、内心、外心、面积

// 面积
double qarea(double x1,double y1,double x2,double y2,double x3,double y3){
	return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2; //公式，求面积
}

//重心：三条中线的交点
Point centroid(Point A, Point B, Point C) {
	Point res = A + B + C;
	return Point(res.x/3, res.y/3);
}

//内切圆圆心
Point incenter(Point A, Point B, Point C) {
	double a = dist(B, C);
	double b = dist(A, C);
	double c = dist(A, B);
	double S = a + b + c;
	double x = (a * A.x + b * B.x + c * C.x) / S;
	double y = (a * A.y + b * B.y + c * C.y) / S;
	return Point(x, y);
}

//外接圆圆心
Point circumcenter(Point A, Point B, Point C) {
	double x1 = A.x, y11 = A.y;
	double x2 = B.x, y2 = B.y;
	double x3 = C.x, y3 = C.y;
	
	double a1 = 2 * (x2 - x1);
	double b1 = 2 * (y2 - y11);
	double c1 = x2*x2 + y2*y2 - x1*x1 - y11*y11;
	
	double a2 = 2 * (x3-x2);
	double b2 = 2 * (y3-y2);
	double c2 = x3*x3 + y3*y3 - x2*x2 - y2*y2;
	
	double x = (c1*b2 - c2*b1) / (a1*b2 - a2*b1);
	double y = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);
	
	return Point(x,y);
}

// 垂心：三边垂直平分线的交点
Point orthocenter(Point A, Point B, Point C) {
	Point cent = centroid(A, B, C);
	cent = Point(cent.x * 3.0, cent.y * 3);
	
	Point circ = circumcenter(A, B, C);
	circ = Point(circ.x * 2.0, circ.y * 2.0);
	return cent - circ;
}
```



### kuangbin

```cpp
// 点相关
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
//`Compares a double to zero`
int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
//square of a double
inline double sqr(double x){return x*x;}
/*
 * Point
 * Point()               - Empty constructor
 * Point(double _x,double _y)  - constructor
 * input()             - double input
 * output()            - %.2f output
 * operator ==         - compares x and y
 * operator <          - compares first by x, then by y
 * operator -          - return new Point after subtracting curresponging x and y
 * operator ^          - cross product of 2d points
 * operator *          - dot product
 * len()               - gives length from origin
 * len2()              - gives square of length from origin
 * distance(Point p)   - gives distance from p
 * operator + Point b  - returns new Point after adding curresponging x and y
 * operator * double k - returns new Point after multiplieing x and y by k
 * operator / double k - returns new Point after divideing x and y by k
 * rad(Point a,Point b)- returns the angle of Point a and Point b from this Point
 * trunc(double r)     - return Point that if truncated the distance from center to r
 * rotleft()           - returns 90 degree ccw rotated point
 * rotright()          - returns 90 degree cw rotated point
 * rotate(Point p,double angle) - returns Point after rotateing the Point centering at p by angle radian ccw
 */
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	void output(){
		printf("%.2f %.2f\n",x,y);
	}
	bool operator == (Point b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b)const{
		return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x;
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	//叉积
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
	//点积
	double operator *(const Point &b)const{
		return x*b.x + y*b.y;
	}
	//返回长度
	double len(){
		return hypot(x,y);//库函数
	}
	//返回长度的平方
	double len2(){
		return x*x + y*y;
	}
	//返回两点的距离
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	Point operator +(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const double &k)const{
		return Point(x*k,y*k);
	}
	Point operator /(const double &k)const{
		return Point(x/k,y/k);
	}
	//`计算pa  和  pb 的夹角`
	//`就是求这个点看a,b 所成的夹角`
	//`测试 LightOJ1203`
	double rad(Point a,Point b){
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	//`化为长度为r的向量`
	Point trunc(double r){
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	//`逆时针旋转90度`
	Point rotleft(){
		return Point(-y,x);
	}
	//`顺时针旋转90度`
	Point rotright(){
		return Point(y,-x);
	}
	//`绕着p点逆时针旋转angle`
	Point rotate(Point p,double angle){
		Point v = (*this) - p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};

// 线相关
/*
 * Stores two points
 * Line()                         - Empty constructor
 * Line(Point _s,Point _e)        - Line through _s and _e
 * operator ==                    - checks if two points are same
 * Line(Point p,double angle)     - one end p , another end at angle degree
 * Line(double a,double b,double c) - Line of equation ax + by + c = 0
 * input()                        - inputs s and e
 * adjust()                       - orders in such a way that s < e
 * length()                       - distance of se
 * angle()                        - return 0 <= angle < pi
 * relation(Point p)              - 3 if point is on line
 *                                  1 if point on the left of line
 *                                  2 if point on the right of line
 * pointonseg(double p)           - return true if point on segment
 * parallel(Line v)               - return true if they are parallel
 * segcrossseg(Line v)            - returns 0 if does not intersect
 *                                  returns 1 if non-standard intersection
 *                                  returns 2 if intersects
 * linecrossseg(Line v)           - line and seg
 * linecrossline(Line v)          - 0 if parallel
 *                                  1 if coincides
 *                                  2 if intersects
 * crosspoint(Line v)             - returns intersection point
 * dispointtoline(Point p)        - distance from point p to the line
 * dispointtoseg(Point p)         - distance from p to the segment
 * dissegtoseg(Line v)            - distance of two segment
 * lineprog(Point p)              - returns projected point p on se line
 * symmetrypoint(Point p)         - returns reflection point of p over se
 *
 */
struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	bool operator ==(Line v) {
		return (s == v.s)&&(e == v.e);
	}
	//`根据一个点和倾斜角angle确定直线,0<=angle<pi`
	Line(Point p,double angle){
		s = p;
		if(sgn(angle-pi/2) == 0){
			e = (s + Point(0,1));
		}
		else{
			e = (s + Point(1,tan(angle)));
		}
	}
	//ax+by+c=0
	Line(double a,double b,double c){
		if(sgn(a) == 0){
			s = Point(0,-c/b);
			e = Point(1,-c/b);
		}
		else if(sgn(b) == 0){
			s = Point(-c/a,0);
			e = Point(-c/a,1);
		}
		else{
			s = Point(0,-c/b);
			e = Point(1,(-c-a)/b);
		}
	}
	void input(){
		s.input();
		e.input();
	}
	void adjust(){
		if(e < s)swap(s,e);
	}
	//求线段长度
	double length(){
		return s.distance(e);
	}
	//`返回直线倾斜角 0<=angle<pi`
	double angle(){
		double k = atan2(e.y-s.y,e.x-s.x);
		if(sgn(k) < 0)k += pi;
		if(sgn(k-pi) == 0)k -= pi;
		return k;
	}
	//`点和直线关系`
	//`1  在左侧`
	//`2  在右侧`
	//`3  在直线上`
	int relation(Point p){
		int c = sgn((p-s)^(e-s));
		if(c < 0)return 1;
		else if(c > 0)return 2;
		else return 3;
	}
	// 点在线段上的判断
	bool pointonseg(Point p){
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
	}
	//`两向量平行(对应直线平行或重合)`
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s)) == 0;
	}
	//`两线段相交判断`
	//`2 规范相交`
	//`1 非规范相交`
	//`0 不相交`
	int segcrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if( (d1^d2)==-2 && (d3^d4)==-2 )return 2;
		return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
			(d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
			(d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
			(d4==0 && sgn((e-v.s)*(e-v.e))<=0);
	}
	//`直线和线段相交判断`
	//`-*this line   -v seg`
	//`2 规范相交`
	//`1 非规范相交`
	//`0 不相交`
	int linecrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		if((d1^d2)==-2) return 2;
		return (d1==0||d2==0);
	}
	//`两直线关系`
	//`0 平行`
	//`1 重合`
	//`2 相交`
	int linecrossline(Line v){
		if((*this).parallel(v))
			return v.relation(s)==3;
		return 2;
	}
	//`求两直线的交点`
	//`要保证两直线不平行或重合`
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	//点到直线的距离
	double dispointtoline(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	//点到线段的距离
	double dispointtoseg(Point p){
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
			return min(p.distance(s),p.distance(e));
		return dispointtoline(p);
	}
	//`返回线段到线段的距离`
	//`前提是两线段不相交，相交距离就是0了`
	double dissegtoseg(Line v){
		return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
	}
	//`返回点p在直线上的投影`
	Point lineprog(Point p){
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	//`返回点p关于直线的对称点`
	Point symmetrypoint(Point p){
		Point q = lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
};

// 圆相关
struct circle{
	Point p;//圆心
	double r;//半径
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
	circle(double x,double y,double _r){
		p = Point(x,y);
		r = _r;
	}
	//`三角形的外接圆`
	//`需要Point的+ /  rotate()  以及Line的crosspoint()`
	//`利用两条边的中垂线得到圆心`
	//`测试：UVA12304`
	circle(Point a,Point b,Point c){
		Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
		Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
		p = u.crosspoint(v);
		r = p.distance(a);
	}
	//`三角形的内切圆`
	//`参数bool t没有作用，只是为了和上面外接圆函数区别`
	//`测试：UVA12304`
	circle(Point a,Point b,Point c,bool t){
		Line u,v;
		double m = atan2(b.y-a.y,b.x-a.x), n = atan2(c.y-a.y,c.x-a.x);
		u.s = a;
		u.e = u.s + Point(cos((n+m)/2),sin((n+m)/2));
		v.s = b;
		m = atan2(a.y-b.y,a.x-b.x) , n = atan2(c.y-b.y,c.x-b.x);
		v.e = v.s + Point(cos((n+m)/2),sin((n+m)/2));
		p = u.crosspoint(v);
		r = Line(a,b).dispointtoseg(p);
	}
	//输入
	void input(){
		p.input();
		scanf("%lf",&r);
	}
	//输出
	void output(){
		printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
	}
	bool operator == (circle v){
		return (p==v.p) && sgn(r-v.r)==0;
	}
	bool operator < (circle v)const{
		return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
	}
	//面积
	double area(){
		return pi*r*r;
	}
	//周长
	double circumference(){
		return 2*pi*r;
	}
	//`点和圆的关系`
	//`0 圆外`
	//`1 圆上`
	//`2 圆内`
	int relation(Point b){
		double dst = b.distance(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r)==0)return 1;
		return 0;
	}
	//`线段和圆的关系`
	//`比较的是圆心到线段的距离和半径的关系`
	int relationseg(Line v){
		double dst = v.dispointtoseg(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r) == 0)return 1;
		return 0;
	}
	//`直线和圆的关系`
	//`比较的是圆心到直线的距离和半径的关系`
	int relationline(Line v){
		double dst = v.dispointtoline(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r) == 0)return 1;
		return 0;
	}
	//`两圆的关系`
	//`5 相离`
	//`4 外切`
	//`3 相交`
	//`2 内切`
	//`1 内含`
	//`需要Point的distance`
	//`测试：UVA12304`
	int relationcircle(circle v){
		double d = p.distance(v.p);
		if(sgn(d-r-v.r) > 0)return 5;
		if(sgn(d-r-v.r) == 0)return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
		if(sgn(d-l)==0)return 2;
		if(sgn(d-l)<0)return 1;
	}
	//`求两个圆的交点，返回0表示没有交点，返回1是一个交点，2是两个交点`
	//`需要relationcircle`
	//`测试：UVA12304`
	int pointcrosscircle(circle v,Point &p1,Point &p2){
		int rel = relationcircle(v);
		if(rel == 1 || rel == 5)return 0;
		double d = p.distance(v.p);
		double l = (d*d+r*r-v.r*v.r)/(2*d);
		double h = sqrt(r*r-l*l);
		Point tmp = p + (v.p-p).trunc(l);
		p1 = tmp + ((v.p-p).rotleft().trunc(h));
		p2 = tmp + ((v.p-p).rotright().trunc(h));
		if(rel == 2 || rel == 4)
			return 1;
		return 2;
	}
	//`求直线和圆的交点，返回交点个数`
	int pointcrossline(Line v,Point &p1,Point &p2){
		if(!(*this).relationline(v))return 0;
		Point a = v.lineprog(p);
		double d = v.dispointtoline(p);
		d = sqrt(r*r-d*d);
		if(sgn(d) == 0){
			p1 = a;
			p2 = a;
			return 1;
		}
		p1 = a + (v.e-v.s).trunc(d);
		p2 = a - (v.e-v.s).trunc(d);
		return 2;
	}
	//`得到过a,b两点，半径为r1的两个圆`
	int gercircle(Point a,Point b,double r1,circle &c1,circle &c2){
		circle x(a,r1),y(b,r1);
		int t = x.pointcrosscircle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r = c2.r = r;
		return t;
	}
	//`得到与直线u相切，过点q,半径为r1的圆`
	//`测试：UVA12304`
	int getcircle(Line u,Point q,double r1,circle &c1,circle &c2){
		double dis = u.dispointtoline(q);
		if(sgn(dis-r1*2)>0)return 0;
		if(sgn(dis) == 0){
			c1.p = q + ((u.e-u.s).rotleft().trunc(r1));
			c2.p = q + ((u.e-u.s).rotright().trunc(r1));
			c1.r = c2.r = r1;
			return 2;
		}
		Line u1 = Line((u.s + (u.e-u.s).rotleft().trunc(r1)),(u.e + (u.e-u.s).rotleft().trunc(r1)));
		Line u2 = Line((u.s + (u.e-u.s).rotright().trunc(r1)),(u.e + (u.e-u.s).rotright().trunc(r1)));
		circle cc = circle(q,r1);
		Point p1,p2;
		if(!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
		c1 = circle(p1,r1);
		if(p1 == p2){
			c2 = c1;
			return 1;
		}
		c2 = circle(p2,r1);
		return 2;
	}
	//`同时与直线u,v相切，半径为r1的圆`
	//`测试：UVA12304`
	int getcircle(Line u,Line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4){
		if(u.parallel(v))return 0;//两直线平行
		Line u1 = Line(u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u.e-u.s).rotleft().trunc(r1));
		Line u2 = Line(u.s + (u.e-u.s).rotright().trunc(r1),u.e + (u.e-u.s).rotright().trunc(r1));
		Line v1 = Line(v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v.e-v.s).rotleft().trunc(r1));
		Line v2 = Line(v.s + (v.e-v.s).rotright().trunc(r1),v.e + (v.e-v.s).rotright().trunc(r1));
		c1.r = c2.r = c3.r = c4.r = r1;
		c1.p = u1.crosspoint(v1);
		c2.p = u1.crosspoint(v2);
		c3.p = u2.crosspoint(v1);
		c4.p = u2.crosspoint(v2);
		return 4;
	}
	//`同时与不相交圆cx,cy相切，半径为r1的圆`
	//`测试：UVA12304`
	int getcircle(circle cx,circle cy,double r1,circle &c1,circle &c2){
		circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
		int t = x.pointcrosscircle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r = c2.r = r1;
		return t;
	}

	//`过一点作圆的切线(先判断点和圆的关系)`
	//`测试：UVA12304`
	int tangentline(Point q,Line &u,Line &v){
		int x = relation(q);
		if(x == 2)return 0;
		if(x == 1){
			u = Line(q,q + (q-p).rotleft());
			v = u;
			return 1;
		}
		double d = p.distance(q);
		double l = r*r/d;
		double h = sqrt(r*r-l*l);
		u = Line(q,p + ((q-p).trunc(l) + (q-p).rotleft().trunc(h)));
		v = Line(q,p + ((q-p).trunc(l) + (q-p).rotright().trunc(h)));
		return 2;
	}
	//`求两圆相交的面积`
	double areacircle(circle v){
		int rel = relationcircle(v);
		if(rel >= 4)return 0.0;
		if(rel <= 2)return min(area(),v.area());
		double d = p.distance(v.p);
		double hf = (r+v.r+d)/2.0;
		double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
		double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
		a1 = a1*r*r;
		double a2 = acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
		a2 = a2*v.r*v.r;
		return a1+a2-ss;
	}
	//`求圆和三角形pab的相交面积`
	//`测试：POJ3675 HDU3982 HDU2892`
	double areatriangle(Point a,Point b){
		if(sgn((p-a)^(p-b)) == 0)return 0.0;
		Point q[5];
		int len = 0;
		q[len++] = a;
		Line l(a,b);
		Point p1,p2;
		if(pointcrossline(l,q[1],q[2])==2){
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
		}
		q[len++] = b;
		if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
		double res = 0;
		for(int i = 0;i < len-1;i++){
			if(relation(q[i])==0||relation(q[i+1])==0){
				double arg = p.rad(q[i],q[i+1]);
				res += r*r*arg/2.0;
			}
			else{
				res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
			}
		}
		return res;
	}
};



// 凸包相关
/*
 * n,p  Line l for each side
 * input(int _n)                        - inputs _n size polygon
 * add(Point q)                         - adds a point at end of the list
 * getline()                            - populates line array
 * cmp                                  - comparision in convex_hull order
 * norm()                               - sorting in convex_hull order
 * getconvex(polygon &convex)           - returns convex hull in convex
 * Graham(polygon &convex)              - returns convex hull in convex
 * isconvex()                           - checks if convex
 * relationpoint(Point q)               - returns 3 if q is a vertex
 *                                                2 if on a side
 *                                                1 if inside
 *                                                0 if outside
 * convexcut(Line u,polygon &po)        - left side of u in po
 * gercircumference()                   - returns side length
 * getarea()                            - returns area
 * getdir()                             - returns 0 for cw, 1 for ccw
 * getbarycentre()                      - returns barycenter
 *
 */
struct polygon{
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n){
		n = _n;
		for(int i = 0;i < n;i++)
			p[i].input();
	}
	void add(Point q){
		p[n++] = q;
	}
	void getline(){
		for(int i = 0;i < n;i++){
			l[i] = Line(p[i],p[(i+1)%n]);
		}
	}
	struct cmp{
		Point p;
		cmp(const Point &p0){p = p0;}
		bool operator()(const Point &aa,const Point &bb){
			Point a = aa, b = bb;
			int d = sgn((a-p)^(b-p));
			if(d == 0){
				return sgn(a.distance(p)-b.distance(p)) < 0;
			}
			return d > 0;
		}
	};
	//`进行极角排序`
	//`首先需要找到最左下角的点`
	//`需要重载号好Point的 < 操作符(min函数要用) `
	void norm(){
		Point mi = p[0];
		for(int i = 1;i < n;i++)mi = min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}
	//`得到凸包`
	//`得到的凸包里面的点编号是0$\sim$n-1的`
	//`两种凸包的方法`
	//`注意如果有影响，要特判下所有点共点，或者共线的特殊情况`
	//`测试 LightOJ1203  LightOJ1239`
	void getconvex(polygon &convex){
		sort(p,p+n);
		convex.n = n;
		for(int i = 0;i < min(n,2);i++){
			convex.p[i] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		if(n <= 2)return;
		int &top = convex.n;
		top = 1;
		for(int i = 2;i < n;i++){
			while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		int temp = top;
		convex.p[++top] = p[n-2];
		for(int i = n-3;i >= 0;i--){
			while(top != temp && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		convex.norm();//`原来得到的是顺时针的点，排序后逆时针`
	}
	//`得到凸包的另外一种方法`
	//`测试 LightOJ1203  LightOJ1239`
	void Graham(polygon &convex){
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1){
			top = 1;
			convex.p[0] = p[0];
			return;
		}
		if(n == 2){
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			if(convex.p[0] == convex.p[1])top--;
			return;
		}
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2;i < n;i++){
			while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2])) <= 0 )
				top--;
			convex.p[top++] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
	}
	//`判断是不是凸的`
	bool isconvex(){
		bool s[2];
		memset(s,false,sizeof(s));
		for(int i = 0;i < n;i++){
			int j = (i+1)%n;
			int k = (j+1)%n;
			s[sgn((p[j]-p[i])^(p[k]-p[i]))+1] = true;
			if(s[0] && s[2])return false;
		}
		return true;
	}
	//`判断点和任意多边形的关系`
	//` 3 点上`
	//` 2 边上`
	//` 1 内部`
	//` 0 外部`
	int relationpoint(Point q){
		for(int i = 0;i < n;i++){
			if(p[i] == q)return 3;
		}
		getline();
		for(int i = 0;i < n;i++){
			if(l[i].pointonseg(q))return 2;
		}
		int cnt = 0;
		for(int i = 0;i < n;i++){
			int j = (i+1)%n;
			int k = sgn((q-p[j])^(p[i]-p[j]));
			int u = sgn(p[i].y-q.y);
			int v = sgn(p[j].y-q.y);
			if(k > 0 && u < 0 && v >= 0)cnt++;
			if(k < 0 && v < 0 && u >= 0)cnt--;
		}
		return cnt != 0;
	}
	//`直线u切割凸多边形左侧`
	//`注意直线方向`
	//`测试：HDU3982`
	void convexcut(Line u,polygon &po){
		int &top = po.n;//注意引用
		top = 0;
		for(int i = 0;i < n;i++){
			int d1 = sgn((u.e-u.s)^(p[i]-u.s));
			int d2 = sgn((u.e-u.s)^(p[(i+1)%n]-u.s));
			if(d1 >= 0)po.p[top++] = p[i];
			if(d1*d2 < 0)po.p[top++] = u.crosspoint(Line(p[i],p[(i+1)%n]));
		}
	}
	//`得到周长`
	//`测试 LightOJ1239`
	double getcircumference(){
		double sum = 0;
		for(int i = 0;i < n;i++){
			sum += p[i].distance(p[(i+1)%n]);
		}
		return sum;
	}
	//`得到面积`
	double getarea(){
		double sum = 0;
		for(int i = 0;i < n;i++){
			sum += (p[i]^p[(i+1)%n]);
		}
		return fabs(sum)/2;
	}
	//`得到方向`
	//` 1 表示逆时针，0表示顺时针`
	bool getdir(){
		double sum = 0;
		for(int i = 0;i < n;i++)
			sum += (p[i]^p[(i+1)%n]);
		if(sgn(sum) > 0)return 1;
		return 0;
	}
	//`得到重心`
	Point getbarycentre(){
		Point ret(0,0);
		double area = 0;
		for(int i = 1;i < n-1;i++){
			double tmp = (p[i]-p[0])^(p[i+1]-p[0]);
			if(sgn(tmp) == 0)continue;
			area += tmp;
			ret.x += (p[0].x+p[i].x+p[i+1].x)/3*tmp;
			ret.y += (p[0].y+p[i].y+p[i+1].y)/3*tmp;
		}
		if(sgn(area)) ret = ret/area;
		return ret;
	}
	//`多边形和圆交的面积`
	//`测试：POJ3675 HDU3982 HDU2892`
	double areacircle(circle c){
		double ans = 0;
		for(int i = 0;i < n;i++){
			int j = (i+1)%n;
			if(sgn( (p[j]-c.p)^(p[i]-c.p) ) >= 0)
				ans += c.areatriangle(p[i],p[j]);
			else ans -= c.areatriangle(p[i],p[j]);
		}
		return fabs(ans);
	}
	//`多边形和圆关系`
	//` 2 圆完全在多边形内`
	//` 1 圆在多边形里面，碰到了多边形边界`
	//` 0 其它`
	int relationcircle(circle c){
		getline();
		int x = 2;
		if(relationpoint(c.p) != 1)return 0;//圆心不在内部
		for(int i = 0;i < n;i++){
			if(c.relationseg(l[i])==2)return 0;
			if(c.relationseg(l[i])==1)x = 1;
		}
		return x;
	}
};

// 最小矩形面积覆盖
//`AB X AC`
double cross(Point A,Point B,Point C){
	return (B-A)^(C-A);
}
//`AB*AC`
double dot(Point A,Point B,Point C){
	return (B-A)*(C-A);
}
//`最小矩形面积覆盖`
//` A 必须是凸包(而且是逆时针顺序)`
//` 测试 UVA 10173`
double minRectangleCover(polygon A){
	//`要特判A.n < 3的情况`
	if(A.n < 3)return 0.0;
	A.p[A.n] = A.p[0];
	double ans = -1;
	int r = 1, p = 1, q;
	for(int i = 0;i < A.n;i++){
		//`卡出离边A.p[i] - A.p[i+1]最远的点`
		while( sgn( cross(A.p[i],A.p[i+1],A.p[r+1]) - cross(A.p[i],A.p[i+1],A.p[r]) ) >= 0 )
			r = (r+1)%A.n;
		//`卡出A.p[i] - A.p[i+1]方向上正向n最远的点`
		while(sgn( dot(A.p[i],A.p[i+1],A.p[p+1]) - dot(A.p[i],A.p[i+1],A.p[p]) ) >= 0 )
			p = (p+1)%A.n;
		if(i == 0)q = p;
		//`卡出A.p[i] - A.p[i+1]方向上负向最远的点`
		while(sgn(dot(A.p[i],A.p[i+1],A.p[q+1]) - dot(A.p[i],A.p[i+1],A.p[q])) <= 0)
			q = (q+1)%A.n;
		double d = (A.p[i] - A.p[i+1]).len2();
		double tmp = cross(A.p[i],A.p[i+1],A.p[r]) *
			(dot(A.p[i],A.p[i+1],A.p[p]) - dot(A.p[i],A.p[i+1],A.p[q]))/d;
		if(ans < 0 || ans > tmp)ans = tmp;
	}
	return ans;
}

//`直线切凸多边形`
//`多边形是逆时针的，在q1q2的左侧`
//`测试:HDU3982`
vector<Point> convexCut(const vector<Point> &ps,Point q1,Point q2){
	vector<Point>qs;
	int n = ps.size();
	for(int i = 0;i < n;i++){
		Point p1 = ps[i], p2 = ps[(i+1)%n];
		int d1 = sgn((q2-q1)^(p1-q1)), d2 = sgn((q2-q1)^(p2-q1));
		if(d1 >= 0)
			qs.push_back(p1);
		if(d1 * d2 < 0)
			qs.push_back(Line(p1,p2).crosspoint(Line(q1,q2)));
	}
	return qs;
}



//`半平面交`
//`测试 POJ3335 POJ1474 POJ1279`
//***************************
struct halfplane:public Line{
	double angle;
	halfplane(){}
	//`表示向量s->e逆时针(左侧)的半平面`
	halfplane(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	halfplane(Line v){
		s = v.s;
		e = v.e;
	}
	void calcangle(){
		angle = atan2(e.y-s.y,e.x-s.x);
	}
	bool operator <(const halfplane &b)const{
		return angle < b.angle;
	}
};
struct halfplanes{
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st,ed;
	void push(halfplane tmp){
		hp[n++] = tmp;
	}
	//去重
	void unique(){
		int m = 1;
		for(int i = 1;i < n;i++){
			if(sgn(hp[i].angle-hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e-hp[m-1].s)^(hp[i].s-hp[m-1].s) ) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	bool halfplaneinsert(){
		for(int i = 0;i < n;i++)hp[i].calcangle();
		sort(hp,hp+n);
		unique();
		que[st=0] = 0;
		que[ed=1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2;i < n;i++){
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)st++;
			que[++ed] = i;
			if(hp[i].parallel(hp[que[ed-1]]))return false;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}
		while(st<ed && sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[que[st]].s))<0)ed--;
		while(st<ed && sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-hp[que[ed]].s))<0)st++;
		if(st+1>=ed)return false;
		return true;
	}
	//`得到最后半平面交得到的凸多边形`
	//`需要先调用halfplaneinsert() 且返回true`
	void getconvex(polygon &con){
		p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
		con.n = ed-st+1;
		for(int j = st,i = 0;j <= ed;i++,j++)
			con.p[i] = p[j];
	}
};
//***************************
```

## 字符串

### 双哈希

```cpp
#include<iostream>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
ll mod[2]={1000000007,998244353};
ll base[2]={43,47};
ll has[3][1000007],po[2][1000007];
char s[1000007];
int ans=0;

void init(){
	po[0][0]=1,po[1][0]=1;
	for(int i=1;i<1000001;i++){
		po[0][i]=(po[0][i-1]*base[0])%mod[0];
		po[1][i]=(po[1][i-1]*base[1])%mod[1];
	}
}

void gethash(string s){
	int len=s.length(),x;
	for(int i=0;i<len;i++){
		x=s[i];
		has[0][i+1]=(has[0][i]*base[0]%mod[0]+x)%mod[0];
		has[1][i+1]=(has[1][i]*base[1]%mod[1]+x)%mod[1];
	}
}
ll getv(int l,int r,int k){
	return (has[k][r]-has[k][l-1]*po[k][r-l+1]%mod[k]+mod[k])%mod[k];
}
map<pair<ll,ll>,ll>ma;

int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%s",s);
		gethash(s);
		int l,r;
		cin>>l>>r;
		printf("%lld %lld\n",getv(l,r,0),getv(l,r,1));
	}
}

```

## 搜索

### 模拟退火

```cpp
#include <bits/stdc++.h>
#define pdd pair <double, double>
using namespace std;

int n;
double ans = 1e18;
pdd p[105], av;

double getp(double l, double r) {
	return (double)rand() / RAND_MAX * (r-l) + l;
}

double cal(pdd now) {
	double res = 0;
	for(int i = 1; i <= n; i++) {
		res += sqrt((now.first-p[i].first)*(now.first-p[i].first)+(now.second-p[i].second)*(now.second-p[i].second));
	}
	return res;
}

void sa() {
	pdd cur = av;
	double curd = cal(av);
	for(double T = 5000; T > 1e-14; T *= 0.996) {
		pdd t = {getp(cur.first-T, cur.first+T), getp(cur.second-T, cur.first+T)};
		double td = cal(t);
		if(td < curd) {
			cur = t; curd = td;
			ans = min(ans, curd);
		}
		else if(exp((curd-td)/T) > getp(0, 1)) {
			cur = t; curd = td;
		}
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &p[i].first, &p[i].second);
		av.first += p[i].first;
		av.second += p[i].second;
	}
	av.first /= n; av.second /= n;
	
	int num = 100;
	while(num--) {
		sa();
	}
	
	printf("%.0lf\n", ans);
}
```



## 其他

### 输入程序运行时间

```cpp
cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
```

