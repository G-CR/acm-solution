## Harmonic Number LightOJ - 1234(稀疏打表)

题意：输入一个n，求 $1+\frac{1}{2}+\frac{1}{3}+...+\frac{1}{n}$ 的值。

思路：由于n比较大，所以全部预处理的数组是开不下的，所以有一种预处理的方式，因为T的大小并不是很大，所以我们可以打一部分的表，然后再在输入后算一部分就可以分担一下空间不够的情况。开一个 $1e6$ 的数组，隔100个数存一个数，比如num是预处理数组，$num[1]$ 存的就是 $[1,100]$ 的和，如果需要查询前8700个数之和是多少，直接查 $num[87]$ 就可以得到答案了，在这种情况下，每个数最多需要再进行99次运算就可以得到最终的结果，比如说 现在 n=1234， 我查询 $num[12]$ 的值，然后从1201开始遍历到1234结束，加上这些值的倒数就可以了。

这个方法并没有完全把表打出来，在T不大的情况下，可以用一部分计算时间去分摊一下空间。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n;
double sum, num[1000006];

int main() {
	for(int i = 1;i <= 100000000; i++) {
		sum += 1.0/(double)i;
		if(i % 100 == 0) num[i/100] = sum;
	}
	
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		double ans = num[n/100];
		for(int i = n/100*100+1; i <= n; i++) {
			ans += 1.0/(double)i;
		}
		
		printf("Case %d: %.11lf\n", ++cas, ans);
	}
}
```

