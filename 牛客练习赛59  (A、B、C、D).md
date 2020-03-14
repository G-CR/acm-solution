[题目链接](https://ac.nowcoder.com/acm/contest/4743#question)

**A - 小乔和小灰灰**

题意：求给定字符串中是否出现“XiaoQiao”和“XiaoHuiHui”

思路：两次遍历，将“XiaoQiao”和“XiaoHuiHui”定义为两个模式串，在给定字符串中找到相应字符继续往后推，看最后模式串的下标大小就知道是否为子序列了。

```cpp
#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.length();
	string t1 = "XiaoQiao";
	string t2 = "XiaoHuiHui";
	bool ok1 = 0, ok2 = 0;
	
	int j = 0; int len1 = t1.length();
	for(int i = 0;i < n; i++) {
		if(t1[j] == s[i]) j++;
	}
	if(j == len1) ok1 = 1;
	
	j = 0; int len2 = t2.length();
	for(int i = 0;i < n; i++) {
		if(t2[j] == s[i]) j++;
	}
	if(j == len2) ok2 = 1;
	
	if(ok1 && ok2) puts("Happy");
	else puts("emm");
}
```



**B - 牛能和小镇**

题意：给n个坐标，根据题给的距离费用公式求出需要连接所有点的最小花费。 公式：| x<sub>i</sub> <sup>2</sup>y<sub>i</sub> - x<sub>j</sub> <sup>2</sup>y<sub>j</sub>  + y<sub>i</sub> <sup>2</sup>(y<sub>i</sub> - 2x<sub>i</sub>) - y<sub>j</sub> <sup>2</sup>(y<sub>j</sub> - 2x<sub>j</sub>) |

思路：公式可以变形一下就比较直观：

|( x<sub>i</sub> <sup>2</sup>y<sub>i</sub> + y<sub>i</sub> <sup>2</sup>(y<sub>i</sub> - 2x<sub>i</sub>) )- ( x<sub>j</sub> <sup>2</sup>y<sub>j</sub> + y<sub>j</sub> <sup>2</sup>(y<sub>j</sub> - 2x<sub>j</sub>) ) | 

这样就可以看出来是两个点各自的坐标经过运算后作差。需要最小的差值，那么排序之后再逐个作差就好了。

```cpp
#include <bits/stdc++.h>
using namespace std;

long long x[100005], y[100005], len[100005];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		len[i] = (x[i]*x[i]*y[i]) + (y[i]*y[i]*(y[i]-2*x[i]));
	}
	sort(len+1, len+1+n);
	long long ans = 0;
	for(int i = 1;i < n; i++) {
		ans += len[i+1]-len[i];
	}
	
	printf("%lld\n", ans);
}
```



**C - 装备合成**

题意：一个装备需要a、b两种材料合成，2个a 3个b 或者 4个a 1个b 都可以，求给定a和b的个数时最多可以合成多少装备。

思路：[参考这个大佬](https://blog.csdn.net/qq_43756519/article/details/104853746)，贪心做法。

如果 **x : y >= 4 : 1**，那么全部使用第二种方案

如果 **x : y <= 2 : 3**，那么全部使用第一种方案

介于之间的就优先使用 2 : 3 的方案直到 x : y = 4 : 1，那么就需要计算需要多少次 2:3的操作就有：

## 				$\frac{x-2n}{y-3n} = 4$

变形一下：

## 				$n = \frac{4y-x}{10}$

n的值或许会取小数，又可能是第一种方法多一个，也有可能第二种方法多一个，此时四舍五入一下就可以得到：

## 				$n = \frac{4y-x+5}{10}$

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &x, &y);
		if(y*4 < x) {
			printf("%lld\n", y);
		}
		else if((double)x/(double)y <= (double)2/(double)3) {
			printf("%lld\n", x/2);
		}
		else {
			long long n = (4*y-x+5)/10;
//			cout << "n = " << n << endl;
			x -= 2*n;
			y -= 3*n;
			printf("%lld\n", n + min(x/4, y));
		}
	}
}
```



**D - 取石子游戏**

题意：XiaoQiao和XiaoHuiHui两个人从石堆里面拿石子，每次把石子分成两部分，一个从中拿走一部分，另一个继续把剩下的分为两部分，再拿走其中的一部分。石堆如果是偶数的话就平均分，不为偶数就有一堆可以多出一个。当其中一个人准备拿石子时只剩下一个，那么这个人就输了，求两个人中谁会赢。（XiaoHuiHui先手）

思路：博弈的话先找找规律：

1个石子的时候肯定是后手赢；

2个石子的时候，先手拿走1个，剩下1个，所以先手就赢了；

3个石子分为 1 和 2， 先手拿走2个，剩下一个，先手赢；

4个石子分为 2 和 2，先手拿走两个，此时，可以看成先手变为后手，2个石子的情形，显然是2个石子的先手赢，也就是本局的后手；

5个石子分为 2 和 3，先手拿走哪一个之后剩下的都是对照前面的 2 和 3，得出本剧后手赢

。。。。。。

就这样一直推可以得出一个结论，石堆一分为二之后，两堆石子对应之前有后手赢的时候，本局先手才可以赢，否则后手赢。

看数据范围之后这样一直递推肯定超时，那么就想如果可以知道给定的n属于先手赢还是后手赢的范围，直接查询的话就会快很多，在常数级就可以得出答案。

看前面几个样例，2和3 是先手赢，4、5、6是后手赢的范围，4 = 2+2，6 = 3+3， 5 = 2+3； 

再看后面的： 7 - 13是先手的范围：7 = 3+4，9 = 4+5， 11 = 5+6， 13 = 6+7； 8 = 4+4， 10 = 5+5， 12 = 6+6；规律应该就很显然了，从已知的范围可以求出后面的范围，比如4、5、6三个数逐个相加的个数为 **6-4=2**； 各自相加的个数为 **6-4+1=3**；那么后面的范围就是 **2+3=5**，这样就可以预处理 1e18之内的先后手赢的范围，之后输入时查询就可以了。

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
vector <pair<long long, long long> > vc;
int _;
long long n;

int main() {
	vc.push_back(make_pair(1, 1));
	vc.push_back(make_pair(2, 3));
	long long tail = 3;
	while(tail < N) {
//		printf("%lld %lld\n", tail+1, tail%2?2*tail:2*tail+1);
		vc.push_back(make_pair(tail+1, tail%2?2*tail:2*tail+1));
		tail = tail%2?2*tail:2*tail+1;
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		for(int i = 0;i < vc.size(); i++) {
			if(n >= vc[i].first && n <= vc[i].second) {
				if(i%2==0) puts("XiaoQiao");
				else puts("XiaoHuiHui");
				break;
			}
		}
	}
}
```

