[题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=4586)

题意：一个骰子🎲有n个面，扔一次骰子每个面朝上的概率都相等。每个面上都有一个数字，扔到多少就能拿多少钱，并且有一些面是特殊面，扔到这些面的话不光可以拿到这个面值，并且还能够再让你扔一次。现在问你参加一次游戏可以得多少钱。

思路：

> 扔一次获得💰的期望 avg 是 所有的面值 sum 除以面数 n；
>
> 扔第二次获得💰的期望是 $\frac{m}{n}*avg$ 
>
> 扔第三次获得💰的期望是 $(\frac{m}{n})^2*avg$
>
> ......
>
> 扔第n次获得💰的期望是$(\frac{m}{n})$ <sup>n-1</sup>$*avg$ 

把这些得的钱都加起来就是一局能拿到的💰了。

求和肯定不能用循环加，因为 n 可以 -> ∞ 。式子列出来可以发现是一个等比数列求和，式子列出来 $avg*\frac{1-(\frac{m}{n})^n}{1-\frac{m}{n}}$  可以发现 n次方趋于 ∞ ，所以那一项为0，那么算出来avg后O(1) 就能得到答案了，注意特判一下m == n 的情况和 avg == 0 的情况。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, x;
double a[202];

int main() {
	while(~scanf("%d", &n)) {
		double avg = 0;
		for(int i = 1;i <= n; i++) scanf("%lf", &a[i]), avg += a[i];
		avg /= (double)n;
		scanf("%d", &m);
		for(int i = 1;i <= m; i++) scanf("%d", &x);
		
		if(avg == 0) puts("0.00");
		else if(m == n) puts("inf");
		else printf("%.2lf\n", avg/(1-(double)m/(double)n));
	}
}
```

 