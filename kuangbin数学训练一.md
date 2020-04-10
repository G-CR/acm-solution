## Fibsieve`s Fantabulous Birthday

##### [LightOJ - 1008](https://vjudge.net/problem/LightOJ-1008)

题意：主要看题目给出的那张图片。一个N*M的格子里面有规律的分布着一些数，然后题目给出图中的一个数，需要你求这个数的坐标(横为x，竖为y)

![题面图片](https://img-blog.csdnimg.cn/20200403234919725.png#pic_center)

思路：数字的颜色已经说明了一切，**颜色相同**的就相当于一组，这个题目主要是数据大，**不允许**循环出现的，同一组数据**开根号**再**向上取整**就刚好是当前的组数你说这不是巧了吗这不是。可以定位到这个数字所在的组数那么求出具体位置就很简单了，先通过这个组数找到最中间的那个数坐标就是 **(组数,组数)**，具体值也好求，然后讨论当前组数的奇偶，对坐标做相应的加减就OK。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long n;

int main() {
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		printf("Case %d: ", ++cas);
		long long cnt = ceil(sqrt(n));
		long long t = cnt*cnt-(cnt-1);
		long long ansx = cnt, ansy = cnt;
		if(t == n) printf("%lld %lld\n", ansx, ansy);
		else {
			long long change = abs(t-n);
			if(cnt%2) {
				if(t < n) ansx -= change;
				else ansy -= change;
			}
			else {
				if(t < n) ansy -= change;
				else ansx -= change;
			}
			printf("%lld %lld\n", ansx, ansy);
		}
	}
}
```



## Knights in Chessboard

##### [LightOJ - 1010](https://vjudge.net/problem/LightOJ-1010/origin)

题意：求那个棋子在互不伤害的情况下能怎么尽可能多的摆在同一个棋盘上。

![题面图片](https://img-blog.csdnimg.cn/20200403235027135.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTQxOTEzOA==,size_16,color_FFFFFF,t_70#pic_center)

思路：根据样例，在草稿纸上画一画，看怎么摆才可以摆得最多，试了那个3 7的之后就不难发现它是在一行中，隔一个位置放一个棋子♟，下一行与上一行错开，同一行照样是隔一个棋子放一个。这样min(n,m) > 2 的情况就完成了✅。只有一行的棋盘有几个格子就放几个这个很好理解，min(n,m) = 2 的就需要注意一下：

| √     | √     | ×     | ×     | √     | √     | **×** | **×** |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **√** | **√** | **×** | **×** | **√** | **√** | **×** | **×** |

2*n 的棋盘应该这么放才能达到最大。每4列一组讨论一下就👌

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, m;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d", &n, &m);
		printf("Case %d: ", ++cas);
		if(n < m) swap(n, m);
		if(m == 1) printf("%d\n", n);
		else if(m == 2) {
			int t = n%4;
			printf("%d\n", n/4*4+(t==0?0:(t>1?4:2)));
		}
		else {
			printf("%d\n", n*m%2?n*m/2+1:n*m/2);
		}	
	}
}
```



## A Childhood Game

##### [LightOJ - 1020](https://vjudge.net/problem/LightOJ-1020/origin)

题意：A 和 B 两个人在取弹珠，每个人每次可以取 1～2 颗，如果A先手，那么最后取的人输了；如果B先手，那么最后取的人就赢了✌️。给出当前有几颗弹珠和谁先手，要你求最后谁会赢。

思路：不同的人先手会有不同的游戏规则，那么就把这个当作两个游戏来分开找规律会比较清晰。

如果Alice先手，情况如下：

|  1   |  2   |  3   |  4   |  5   |  6   |  7   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  B   |  A   |  A   |  B   |  A   |  A   |  B   |

如果Bob先手，情况如下：

| 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| B    | B    | A    | B    | B    | A    | B    |

不难发现Alice先手就是 “BAA” 的规律， Bob先手就是“BBA”的规律。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long n;
string s;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld", &n);
		cin >> s;
		printf("Case %d: ", ++cas);
		int t = n%3;
		if(s == "Alice") {
			if(t == 1) puts("Bob");
			else puts("Alice");
		}
		else {
			if(t == 0) puts("Alice");
			else puts("Bob");
		}
	}
}
```



## Integer Divisibility

##### [LightOJ - 1078](https://vjudge.net/problem/LightOJ-1078/origin)

题意：给一个数 n， 再给一个数 m，问多少位的 m 可以被 n 整除，输出最小符合条件的 “mmmmm....” 的位数。

思路：最直接的思路不就是 t = m; m = m*10+t 一直循环下去，直到找到答案为止🐎，或许只有我这么菜吧。学到一个**同余定理**，也就是说我们最终答案符合标准无非就是 :

**(m + m * 10 + m * 100 + ...) % n == 0**

但是问题就在于或许“mmmm...”的位数会很多，而且比较大的数字取模还挺费时间的，用之前那个方法我交过一次反馈是超时估计就是因为这个吧。上述这个式子其实关注的并不是这个m最后是多少，而是我到底给这个m乘过多少次，所以它来了：

**同余定理：(m%n + m * 10%n + m * 100%n + ...) % n == 0**

这个乍一看还挺难以理解的，可以想像括号中的每一次取模都是除法列竖式中取余数的操作，只不过这个被除数会会一直变大，直到有一个可以整出的数据出来竖式也就结束了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, digit, cas;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &digit);
		printf("Case %d: ", ++cas);
		int t = digit%n, ans = 1;
		while(t) {
			t = (t*10+digit)%n;
			ans++;
		}
		printf("%d\n", ans);
	}
}
```



## Ekka Dokka

##### [LightOJ - 1116](https://vjudge.net/problem/LightOJ-1116/origin)

题意：给一个数W，需要输出一个N，一个M；N为奇数，M为偶数。并且 $W = N * M$ 。并且M需要最小。

思路：如果W给的是奇数，那么没有答案，奇数和偶数的乘积一定为偶数；如果给的是偶数，如果没有最后一个约束条件直接输出 1 W 就完事了，那么也就是把W中的偶数都抽出来就好了，循环除以2，抽出来的是M，剩下的是N就👌。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long w;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld", &w);
		printf("Case %d: ", ++cas);
		if(w % 2) puts("Impossible");
		else {
			long long t = w;
			while(w % 2 == 0) {
				w /= 2;
			}
			printf("%lld %lld\n", w, t/w);
		}
	}
}
```



## Mad Counting

##### [LightOJ - 1148](https://vjudge.net/problem/LightOJ-1148/origin)

题意：一个人统计镇上有多少个人，但是他不想一个一个的去数，就想到了一个办法，在镇上逮到n个人👨，一个一个问“除了你自己还有多少人跟你在2010年支持的世界杯是同一个球队”，这n个人中每个人都只会被问到一次；求镇上最少有多少人。（为啥他们镇上的人这么清楚谁支持什么队，我们班谁支持湖人我都不清楚）

思路：询问的目的就是把支持同一个球队的人给分组，比如样例中的 1 1 2 2，询问了四个人，第一个人表示除了他还有一个人跟他支持同一个球队，第二个人也是这么说，为了让人数最少我们可以认为他们指的就是彼此；如果这时候再出来一个表示1的话，那么他跟前面两个就没得关系了，就需要另一个隐藏的人跟他一组，所以只要有一个人说1，那么镇上至少就会有两个人了。那么同理一个人说2，就证明除了他自己还有两个人跟他一组，后面又有一个说2，那么为了人口最少我们就把后面说2的加入前面说2的；如果后面又来了一个说2的那么仍然可以加入第一个说2的那一组。规律就已经很明显了： 说跟有i个人跟自己一样，那么这一组就可以加入i+1个人。往后一直读取，满了清零加入答案一直搞就👌

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, x;
map <int, int> a;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		a.clear();
		int ans = 0;
		scanf("%d", &n);
		printf("Case %d: ", ++cas);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(a[x] == 0) ans += (x+1);
			a[x]++;
			if(a[x] == x+1) a[x] = 0;
		}
		printf("%d\n", ans);
	}
}
```



## Josephus Problem

##### [LightOJ - 1179](https://vjudge.net/problem/LightOJ-1179/origin)

题意：n个人站成一个圆，1号与n号相连， 1号与2号相连的那种。从1开始报数，报到k时杀掉他，移除这个人；并从k+1个开始重新从0报数，下一个保k的继续杀死，移除；如此循环下来，求最后一个幸存者在最开始的圆圈中的编号是多少。

思路：这是一个**[约瑟夫环](https://blog.csdn.net/u011500062/article/details/72855826?utm_source=app)**的问题。简单分析一下，幸存者的编号在最后剩下他的时候编号肯定是0；那么试想一下，在还剩两个人的时候这个幸存者的编号应该是多少才可以幸存？因为幸存后的他编号是1，就是从还剩两的人的时候死了另一个后往前移动k位变成的，我们把这个k加上去后取一个当时多少人的模就可以得到当时的编号，如此往复就可以得到那个人时候这个幸存者的站位编号了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: ", ++cas);
		int ans = 0;
		for(int i = 2;i <= n; i++) {
			ans = (ans+k)%i;
			cout << ans+1 << endl;
		}
		printf("%d\n", ans+1);
	}
}
```



## Internet Service Providers

[LightOJ - 1275](https://vjudge.net/problem/LightOJ-1275/origin)

题意：利润 = $T * (C - T * N)$ 求 使利润最大时的最小 T

思路：整理一下式子：$W = -N * T$<sup>2</sup> $ + C * T$ 就是一个开口向下的抛物线，需要求W取最大值的时候T的值，需要注意的是在W最大的时候T可能不是整数所以需要比较一下 T 取 ans 与 ans+1 的大小。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
double n, c;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf", &n, &c);
		int ans = c/2/n;
		if(ans*(c-n*ans) < (ans+1)*(c-n*(ans+1))) ans++;
		printf("Case %d: %d\n", ++cas, n==0?0:ans);
	}
}
```



## Positive Negative Sign

[LightOJ - 1294](https://vjudge.net/problem/LightOJ-1294/origin)

题意：给一个n，一个m，其中 n 可以被 2*m 整除，然后有一个序列，从 1 开始一直到 n，1～m为负号， m+1 ～ 2*m为正号，2m+1 ～ 3m 为负号…问这样的一个序列的和为多少。

思路：从样例入手 题面中给的 12  3 的序列是这样的：

​			**-1 -2 -3** +4 +5 +6 **-7 -8 -9** +10 +11 +12

数据很大，所以枚举或者预处理是不要想的了，规律题。看前六个数据，第一个和第四个相加为3 也就是 m，第二个和第五个相加也是m，第三个和第六个相加仍然是m，7～12个也是这样的规律。所以我们可以每 2*m 个数据一组，每组之和就是 m * m，再乘以组数就👌

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &m);
		printf("Case %d: ", ++cas);
		long long cnt = n/(2*m);
		long long sum = m*m;
		printf("%lld\n", sum*cnt);
	}
}
```



## Largest Box

[LightOJ - 1297](https://vjudge.net/problem/LightOJ-1297/origin)

题意：一张长为L，宽为W 的纸，照着图中的裁剪方式将四个角各剪出一个边长为x的正方形，并沿着x的边折起来，问x取多大这个折起来的无盖长方体的体积可以最大。

![题面图片](https://img-blog.csdnimg.cn/20200405135341535.png#pic_center)

思路：长方体的体积表达式 $V = (L - 2 * x) * (W - 2 * x) * x$ 

显然是一元三次方程 展开后：

 $V = 4x$<sup>3</sup> $- 2(L+W)x$<sup>2</sup> $+ LWx$ 

求导得：

$F = 12x$<sup>2</sup> $- 4(L+W)x + LW$

这个函数的图像是这样的 /\/ ，所以极大值在求导后为零点的比较小的那个位置。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
double l, w;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf", &l, &w);
		double pos = (4*(l+w) - sqrt(16*(l+w)*(l+w)-4*12*l*w))/24;
		printf("Case %d: %lf\n", ++cas, (l-2*pos)*(w-2*pos)*pos);
	}
}
```



## Unlucky Bird

[LightOJ - 1311](https://vjudge.net/problem/LightOJ-1311/origin)

题意：一只鸟在两辆相向而行的火车之间之间飞行，左边的火车速度v1，右边的火车速度v2，🐦的速度为v3，这只鸟在这两辆车之间飞行，遇到左边的火车时调头向右，遇到右边的火车调头向左，这样往复，当这两辆火车距离为d时开始减速，左边的减速度问a1，右边的减速度为a2，🐦依然往复飞行，当火车距离刚好为0的时候两辆车的速度都是0。求d，和距离为d之后🐦的飞行路程。

思路：物理题，注意一点就行了，两辆火车不一定在同一时刻停车。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
double v1, v2, v3, a1, a2;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
		double x1 = (v1*v1)/(2*a1);
		double x2 = (v2*v2)/(2*a2);
		double d = x1+x2; 
		double t = max(v1/a1, v2/a2);
		double fin = v3*t;
		printf("Case %d: %.8lf %.8lf\n", ++cas, d, fin);
	}
}
```



## Billiard Balls

[LightOJ - 1323](https://vjudge.net/problem/LightOJ-1323/origin)

**题意**：一堆球在桌子上面运动，难免会碰到一起，要么是球和球，要么是球和桌子，题目也给出了球和球碰撞💥后的轨迹如图：

![撞击墙面](https://img-blog.csdnimg.cn/20200406161908292.png#pic_center)

<center>撞击墙面的情况</center>
![两球相撞](https://img-blog.csdnimg.cn/20200406162050321.png#pic_center)

​		           

<center>两球相撞</center>



![多求相撞](https://img-blog.csdnimg.cn/20200406162126806.png#pic_center)

<center>多球相撞</center>

需要求k秒后所有球的位置，并且排序。

**思路**：看得出来，其实这些碰撞可以看成是没有碰撞过，这几个球在碰撞后走的都是对方本该走的路，那么我们可以看成这些球都没有收到任何影响按照自己原来的方向运动就可以了，换句话说就是因为最后输出并不需要每个球的编号对应所在的位置，可以忽略球之间的碰撞，考虑球与桌面的就可以了。球的运动可以分为x方向和y方向，这个球可能走了很久以至于经过了很多次起点，那么如果在x方向就需要对路程K % 2*L 就是球走的有效距离。再分析位于距离起点的什么位置就好了。

```cpp
#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
} poi[1005];

bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int up(int m, int l, int k) {
	int ans = k % (l*2);
	if(ans > (l-m)) {
		if(ans >= 2*l-m) {
			m = ans + m - 2*l;
		}
		else {
			m = 2*l - ans - m;
		}
	}
	else {
		m += ans;
	}
	return m;
}

int down(int m, int l, int k) {
	int ans = k % (l*2);
	if(ans > m) {
		if(ans > l+m) {
			m = 2*l - ans + m;
		}
		else {
			m = ans - m;
		}
	}
	else {
		m -= ans;
	}
	return m;
}

int main() {
	int _, cas = 0;
	scanf("%d", &_);
	while(_--) {
		int l, w, n, k;
		char a, b;
		scanf("%d %d %d %d", &l, &w, &n, &k);
		printf("Case %d:\n", ++cas);
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %c %c", &poi[i].x, &poi[i].y, &a, &b);
			if(a == 'N') poi[i].y = up(poi[i].y, w, k);
			else poi[i].y = down(poi[i].y, w, k);
			
			if(b == 'E') poi[i].x = up(poi[i].x, l, k);
			else poi[i].x = down(poi[i].x, l, k);
		}
		
		sort(poi+1, poi+1+n, cmp);
		for(int i = 1;i <= n; i++) {
			printf("%d %d\n", poi[i].x, poi[i].y);
		}
	}
}
```



## Aladdin and the Optimal Invitation

[LightOJ - 1349](https://vjudge.net/problem/LightOJ-1349/origin)

题意：在一个 n * m 的格子里，每一个 (u , v) 中都有 w 个人，现在需要将格子中的所有人都聚在一个格子里，从一个(x, y) 移动到 (p, q) 每个人需要 **|x-p|+|y-q|** 步，现在问最少需要多少步才可以把所有人聚在一起，求格子的坐标

思路：分别对x, y 排序， 分别找到中位数的人的坐标就可以了

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, m, n, q;
struct node {
	int x, y, peo;
}a[50005];

bool cmp1(node p, node q) {
	return p.x < q.x;
}

bool cmp2(node p, node q) {
	return p.y < q.y;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d %d", &m, &n, &q);
		int sum = 0;
		for(int i = 1;i <= q; i++) {
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].peo);
			sum += a[i].peo;
		}
		int now = 0, ansx, ansy;
		int mid = (sum+1)/2;
		sort(a+1, a+1+q, cmp1);
		for(int i = 1;i <= q; i++) {
			now += a[i].peo;
			if(now >= mid) {
				if(sum%2) ansx = a[i].x;
				else {
					if(now == mid) ansx = (a[i].x+a[i+1].x)/2;
					else ansx = a[i].x;
				}
				break;
			}
		}
		
		now = 0;
		sort(a+1, a+1+q, cmp2);
		for(int i = 1;i <= q; i++) {
			now += a[i].peo;
			if(now >= mid) {
				if(sum%2) ansy = a[i].y;
				else {
					if(now == mid) ansy = (a[i].y+a[i+1].y)/2;
					else ansy = a[i].y;                           
				}
				break;
			}
		}
		
		printf("Case %d: %d %d\n", ++cas, ansx, ansy);
	}
}
```



## IP Checking

[LightOJ - 1354](https://vjudge.net/problem/LightOJ-1354/origin)

**题意：** 给两串IP地址，一串是10进制的，一串是2进制的，问这两个IP地址是否相同

**思路：**就把进制换成相同的一比就👌了

```cpp
#include <bits/stdc++.h>
using namespace std;

stack <int > sta;
int _;
string a, b;
vector <int> chea, cheb;

int change(string s) {
	int n = s.length();
	int start = n;
	for(int i = 0;i < n; i++) {
		if(s[i] != 0) {
			start = i;
			break;
		}
	}
	for(int i = start; i < n; i++) sta.push(s[i]-'0');
	int t = 1, res = 0;
	while(!sta.empty()) {
		int k = sta.top(); sta.pop();
		res += (t*k); t *= 2;
	}
	return res;
}

bool check() {
	for(int i = 0;i < 4; i++) {
		if(chea[i] != cheb[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		chea.clear(); cheb.clear();
		cin >> a >> b;
		int p = 0;
		for(int i = 0;i < a.length(); i++) {
			if(a[i] != '.') {
				p *= 10;
				p += (a[i]-'0');
			}
			else {
				chea.push_back(p);
				p = 0;
			} 
		}
		chea.push_back(p);
		
		p = 4;
		int head = 0;
		while(p--) {
			string q = b.substr(head, 8);
			cheb.push_back(change(q));
			head += 9;
		}
		printf("Case %d: %s\n", ++cas, check()?"Yes":"No");
	}
}
```



## Answering Queries

[LightOJ - 1369](https://vjudge.net/problem/LightOJ-1369/origin)

题意：对输入的A数组进行以下操作：

```cpp
long long f( int A[], int n ) { // n = size of A

    long long sum = 0;

    for( int i = 0; i < n; i++ )

        for( int j = i + 1; j < n; j++ )

            sum += A[i] - A[j];

    return sum;

}
```

之后会有两种操作

1. 输入 0 x y，A[x] = y
2. 输入1，输出最新的sum

思路：如果按照题目中给的函数求和，那么只是求和的时间最坏就需要100秒。所以需要另外找方法。观察之后发现每次都是 **a[i]** 与后面的所有元素相减，是否可以通过预处理后面的数据进行缩短时间呢，那就需要用后缀和的办法了，算出a[i]在当前位置有多少个会与后面的相减；O(n)的时间就可以计算出来sum。之后就是改变某一个a[i]的值，当然修改之后sum的值也需要随之改变，也就是看 a[i] 对于在它之前的数，a[i] 充当的就是减数， 对于在a[i]之后的数充当的就是被减数，O(1)的时间就可以搞出来，就没👌了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long besum[100005], a[100005];
long long n, q, k, b, c;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &q);
		for(int i = 0;i < n; i++) {
			scanf("%lld", &a[i]);
		}
		
		besum[n-1] = a[n-1];
		for(int i = n-2;i >= 0; i--) {
			besum[i] = besum[i+1] + a[i];
		}
		
		long long sum = 0;
		for(int i = 0;i < n-1; i++) {
			sum += (a[i]*(n-1-i)-besum[i+1]);
		}
				
		printf("Case %d:\n", ++cas);
		
		while(q--) {
			scanf("%lld", &k);
			if(k == 1) {
				printf("%lld\n", sum);
			} 
			else {
				scanf("%lld %lld", &b, &c);
				long long t = c-a[b];
				a[b] = c;
				sum = sum - t*b + t*(n-b-1);
			}
		}
    
	}
}
```



## Consistent Verdicts

[LightOJ - 1410](https://vjudge.net/problem/LightOJ-1410/origin)

题意：在一个平面上有N个人，每个人的听力范围都相同但未知，现在每个人都在自己的点开枪，在与他距离在听力范围内的人都听到枪声，求在每个人开一遍枪之后每个人听到多少声的枪响的可能组合的数量。

思路：有多少种不同的距离就是解的数量

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n;
long long x[705], y[705], dis[500000];

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &x[i], &y[i]);
		}
		
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				dis[++cnt] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
		
		sort(dis+1, dis+1+cnt);
		int num = unique(dis+1, dis+1+cnt) - dis;
		printf("Case %d: %d\n", ++cas, num);
	}
}
```



## February 29

[LightOJ - 1414](https://vjudge.net/problem/LightOJ-1414/origin)

题意：给出两个年月日，算这个时间区间里面有多少个2月29号。

思路：闰年定义就不说了。众所周知，一个数除以另一个数就可以算出被除数中包含多少个除数，这个题目也就是这个思路，大年份减小年份再除以需要除的数就可以 算出 **(小年份, 大年份]** 之间包含的除数。

用这个思路求出 年份之间的 可以整除 4 的年份个数， 可以整除 400 的年份个数， 可以整除100 的年份个数。前两个相加再减去第三个就可以得到一个近似答案了。

然后再讨论这两个边界年份，小年份如果是闰年并且日期早于 2月29日 答案就需要+1；大年份如果是闰年，但是日期早于 2月29日 那么答案需要 -1；最后就可以输出了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
string month1, day1, month2, day2;
long long year1, year2;
map <string, int> mon;

void init() {
	mon["January"] = 1; mon["February"] = 2; mon["March"] = 3;
	mon["April"] = 4; mon["May"] = 5; mon["June"] = 6; 
	mon["July"] = 7; mon["August"] = 8; mon["September"] = 9; 
	mon["October"] = 10; mon["November"] = 11; mon["December"] = 12;
}

bool check(long long year) {
	if(year % 100 == 0) {
		if(year % 400 == 0) return 1;
		else return 0;
	}
	else if(year % 4 == 0) return 1;
	else return 0;
}

int main() {
	init();
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		cin >> month1 >> day1 >> year1;
		cin >> month2 >> day2 >> year2;
		printf("Case %d: ", ++cas);
		
		int ans = (year2/4-year1/4) + (year2/400-year1/400) - (year2/100-year1/100);
		if(check(year1) && mon[month1] <= 2) ans++;
		if(check(year2) && !(mon[month2] >= 3 || (mon[month2] == 2 && day2 == "29,"))) ans--;
		
		printf("%d\n", ans);
	}
}
```



## Eid

[LightOJ - 1024](https://vjudge.net/problem/LightOJ-1024/origin)

题意： 求最小公倍数

思路：数据很大，需要Java大数来做

```java
import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int tt = 1;tt <= t; tt++) {
			int n = input.nextInt();
			BigInteger ans, m, k;
			m = input.nextBigInteger();
			ans = m;
			for(int i = 1;i < n; i++) {
				m = input.nextBigInteger();
				k = ans.gcd(m);
				ans = ans.multiply(m).divide(k);
			}
			System.out.println("Case "+ tt + ": " + ans);
			System.gc();
		}
	}
}
```



## Monkey Tradition

[LightOJ - 1319](https://vjudge.net/problem/LightOJ-1319/origin)

题意：N个🐒爬N个长为L的竹竿，每个🐒每个单位时间爬的高度不一样，最后就会有长度长度剩余，因为不够🐒一次爬的嘛，就根据这些不同的剩余长度，求L（🐒单位时间爬的高度都是质数）。

思路：中国剩余定理，可以[学](https://blog.csdn.net/S_999999/article/details/89298179)一下。

```cpp
#include <bits/stdc++.h>
using namespace std;

long long m[20], a[20];
int _, n;

void exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {
		x = 1;
		y = 0;
	}
	else {
		exgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
}

long long CRT() {
	long long M = 1;
	for(int i = 1;i <= n; i++) M *= m[i];
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		long long x, y, Mi;
		Mi = M/m[i];
		exgcd(Mi, m[i], x, y);
		ans = (ans + a[i]*Mi*x) % M;
	}
	
	if(ans < 0) ans += M;
	return ans;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &m[i], &a[i]);
		}
		printf("Case %d: %lld\n", ++cas, CRT());
	}
}
```

