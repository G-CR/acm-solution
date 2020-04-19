[比赛链接](https://ac.nowcoder.com/acm/contest/5158#question)

## B - 组队 

思路：在排好序的能力值数组里面搞一个头指针，搞一个尾指针，如果尾部的能力值-头部的能力值在k之内，那么就让尾指针再往后移动，反之，记录当前尾部与头部的差值与答案取max，并且头指针向后移动一位。往复搞一搞就出来了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		
		int head = 1, tail = 1;
		int ans = 0;
		while(head <= n) {
			if(a[tail] - a[head] <= k) {
				if(tail == n) break;
				tail++;
			}
			else {
				ans = max(ans, tail-head);
				head++;
			}
		}
		printf("%d\n", ans);
	}
}
```



## D - 牛妹吃豆子

思路：因为是统一把修改放在一起，然后把查询放在一起，就可以通过求二维差分的方法来修改矩阵中的值，之后求一次二维前缀和就可以 O(1) 求查询了。

二维差分求法 ：

 $1、val[x1][y1]++ $

$2、val[x1][y2+1]--$

$3、val[x2+1][y1]--$

$4、val[x2+1][y2+1]++$

二维前缀和求法：

$sum[i][j] = val[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]$

求指定 (x1,y1) ~(x2,y2) 矩阵范围的和的求法：

$sum[x1][y1]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]$

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, k, q, w1, h1, w2, h2;
long long val[2002][2002];

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	while(k--) {
		scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
		val[w1][h1]++;
		val[w1][h2+1]--;
		val[w2+1][h1]--;
		val[w2+1][h2+1]++;
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			val[i][j] = val[i][j] + val[i-1][j] + val[i][j-1] - val[i-1][j-1];
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			val[i][j] = val[i][j] + val[i-1][j] + val[i][j-1] - val[i-1][j-1];
		}
	}
	
	while(q--) {
		scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
		printf("%lld\n", val[w2][h2]-val[w1-1][h2]-val[w2][h1-1]+val[w1-1][h1-1]);
	}
}
```



## F - 斗兽棋 

思路：舔🐶水题

```cpp
#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
	cin >> s1 >> s2;
	if(s1 == "elephant") {
		if(s2 == "mouse") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "tiger") {
		if(s2 == "elephant") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "cat") {
		if(s2 == "tiger") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "mouse") {
		if(s2 == "cat") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
}
```



## G - 做题 

思路：排好序一直加到不能加的位置，记录当前在第几个题目。

```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];

int main() {
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	
	long long sum = 0;
	int ans = n;
	for(int i = 1;i <= n; i++) {
		if(sum + a[i] > m) {
			ans = i-1;
			break;
		}
		sum += a[i];
	}
	
	printf("%d\n", ans);
}
```



## H - 人人都是好朋友 

思路：离散化+并查集：已经成为朋友的人可以记录一个共同的朋友，这样在查询的时候就好处理一些，这样就需要并查集来帮忙，暂时让你的好朋友当你的👨。但是呢这个题目，人们的编号有点大，如果直接上map来存储人的编号的话那肯定会超时的，但是他的总人数没有那么多，我们就可以把他们的编号离散化一下，整成在1e7范围内的连续的数，就可以在数组里面整了。

直接上map的惨案:

```cpp
// 超时代码 没有离散化直接用map并查集
#include <bits/stdc++.h>
using namespace std;

int _, n, c;
int a, b;
map <int, int> fa;
map < pair<int, int>, bool> bad;
bool ok;

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		fa.clear(); bad.clear();
		scanf("%d", &n);
		while(n--) {
			ok = 1;
			scanf("%d %d %d", &a, &b, &c);
			if(fa[a] == 0) fa[a] = a;
			if(fa[b] == 0) fa[b] = b;
			long long u = find(a);
			long long v = find(b);
			
			if(c == 1) {
				if(bad[make_pair(u, v)]) ok = 0;
				else {
					fa[u] = v;
				}
			}
			else {
				if(u == v) ok = 0;
				else {
					bad[make_pair(u, v)] = 1;
					bad[make_pair(u, v)] = 1;
				}
			}
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}
```

正确代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n;
struct node {
	int a, b, c;
} relation[2000006];
int fa[2000006], fin[2000006];

int find(int x) {
	if(fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		bool ok = 1;
		scanf("%d", &n);
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d", &relation[i].a, &relation[i].b, &relation[i].c);
			fin[++cnt] = relation[i].a;
			fin[++cnt] = relation[i].b;
		}
		
		sort(fin+1, fin+1+cnt);
		cnt = unique(fin+1, fin+1+cnt)-fin-1;
		for(int i = 1;i <= cnt; i++) fa[i] = i;
		for(int i = 1;i <= n; i++) {
			relation[i].a = lower_bound(fin+1, fin+1+cnt, relation[i].a) - fin;
			relation[i].b = lower_bound(fin+1, fin+1+cnt, relation[i].b) - fin;
			
			int u = find(relation[i].a);
			int v = find(relation[i].b);
			
			if(relation[i].c == 1) {
				if(u != v) fa[u] = v;
			}
			else {
				if(u == v) ok = 0;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}

```



## I - 求和

思路：如果题目中给的是完全独立的n个节点，那么就可以直接上树状数组或者线段树搞一搞就可以出答案了。

但是现在的节点有父子关系，导致不能简单的使用这两个工具来解题，那么怎么办呢？

当然首先要把这些点的关系先梳理一遍：有父子关系的都绑定起来，通过父亲节点就可以知道所有子节点的和，那么怎么才能搞成这样的关系呢，就dfs序跑一遍呗，通过遍历顺序给每个节点安排上新的时间戳序号，递归回到父节点的时候就刚好是一个连续的区间，区间中就包括了自身与所有的子节点了。 然后有了这些关系我们就可以用树状数组或者线段树来求解了。

```cpp
#include <bits/stdc++.h>
using namespace std;

vector <int> g[1000006];
int val[1000006], times;
int l[1000006], r[1000006];
int n, m, k;
long long sum[1000006];

int lowbit(int x) {
	return x&-x;
}

void update(int pos, int num) {
	while(pos <= n) {
		sum[pos] += num;
		pos += lowbit(pos);
	}
}

long long getsum(int pos) {
	long long res = 0;
	while(pos) {
		res += sum[pos];
		pos -= lowbit(pos);
	}
	return res;
}

void dfs(int son, int father) {
	l[son] = ++times;
	update(times, val[son]);
	for(int i = 0;i < g[son].size(); i++) {
		int grandson = g[son][i];
		if(grandson != father) {
			dfs(grandson, son);
		}
	}
	r[son] = times;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &val[i]);
	}
	int u, v;
	for(int i = 1;i < n; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(k, 0);
//	for(int i = 1;i <= n; i++) printf("%d ", l[i]); puts("");
	int choose, x, y;
	for(int i = 1;i <= m; i++) {
		scanf("%d", &choose);
		if(choose == 1) {
			scanf("%d %d", &x, &y);
			update(l[x], y);
		}
		else {
			scanf("%d", &x);
			printf("%lld\n", getsum(r[x])-getsum(l[x]-1));
		}
	}
}
```



## J - 建设道路

思路：直接模拟的话 O (n^2)，我们可以先把这些需要加起来的完全平方式列出来找找规律 :

(x<sub>1</sub>-x<sub>2</sub>)<sup>2</sup> + (x<sub>1</sub>-x<sub>3</sub>)<sup>2</sup> + (x<sub>1</sub>-x<sub>4</sub>)<sup>2</sup> + (x<sub>1</sub>-x<sub>5</sub>)<sup>2</sup> +  ... + (x<sub>1</sub>-x<sub>n</sub>)<sup>2</sup> 

​			    (x<sub>2</sub>-x<sub>3</sub>)<sup>2</sup> + (x<sub>2</sub>-x<sub>4</sub>)<sup>2</sup> + (x<sub>2</sub>-x<sub>5</sub>)<sup>2</sup> + ... + (x<sub>2</sub>-x<sub>n</sub>)<sup>2</sup>

​								(x<sub>3</sub>-x<sub>4</sub>)<sup>2</sup> + (x<sub>3</sub>-x<sub>5</sub>)<sup>2</sup> + ... + (x<sub>3</sub>-x<sub>5</sub>)<sup>2</sup>

​												(x<sub>4</sub>-x<sub>5</sub>)<sup>2</sup> + ... + (x<sub>4</sub>-x<sub>n</sub>)<sup>2</sup> 

​															......

展开之后：

(n-1) * a<sub>1</sub><sup>2</sup> + a<sub>2</sub><sup>2</sup> + a<sub>3</sub><sup>2</sup> + a<sub>4</sub><sup>2</sup> +a<sub>5</sub><sup>2</sup> + ... + a<sub>n</sub><sup>2</sup>   -  2 * a<sub>1</sub> * (a<sub>2</sub> + a<sub>3</sub> + a<sub>4</sub> + a<sub>5</sub> + ... + a<sub>n</sub>)

​		 (n-2) * a<sub>2</sub><sup>2</sup> + a<sub>3</sub><sup>2</sup> + a<sub>4</sub><sup>2</sup> +a<sub>5</sub><sup>2</sup> + ... + a<sub>n</sub><sup>2</sup>   -  2 * a<sub>2</sub> * (a<sub>3</sub> + a<sub>4</sub> + a<sub>5</sub> + ... + a<sub>n</sub>)

​                  (n-3) * a<sub>3</sub><sup>2</sup> + a<sub>4</sub><sup>2</sup> +a<sub>5</sub><sup>2</sup> + ... + a<sub>n</sub><sup>2</sup>   -  2 * a<sub>3</sub> * (a<sub>4</sub> + a<sub>5</sub> + ... + a<sub>n</sub>)

​											......

可以发现这些式子，减号👈相同的项相加都是 (n-1) 项， 发现这个就可以集中O(n) 处理了，减号 👉 的规律也不难找，常数2不用管，后面跟的是一个有顺序的a，括号里的就可以用前缀和的方式 pre[n] - pre[i] 就可以得到了。写的时候记得取模问题就不大。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n;
long long a[500005], presum[500005], res1, res2;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		res1 = (res1+(a[i]*a[i]%mod))%mod;
		presum[i] = (presum[i-1] + a[i]) % mod;
	}
	res1 = (res1 * (n-1)) % mod;
	
	for(int i = 1;i <= n; i++) {
//		cout << presum[i] << " ";
		res2 = (res2 + ((presum[n]-presum[i])%mod*a[i])%mod)%mod;
	}
	res2 = (2*res2)%mod;
//	puts("");
	
//	cout << "res1 = " << res1 << " res2 = " << res2 << endl;
	printf("%lld\n", (res1-res2+mod)%mod);
}
```

