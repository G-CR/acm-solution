## Leading and Trailing LightOJ - 1282

题意：给n和k，求 $n^k$ 的前三位和后三位

思路：后三位用快速幂模上1000搞一搞就出来了，前三位主要是一直在扩张，并且需要后面的数来提供火力，所以如果直接舍弃掉后面的数的话可能会确实一些京精度，那么如何操作才能比较合理呢，我们需要考虑一下怎么才能把最高位束缚起来，就像是最低位一样位置不会改变，当然是把它搞到小数点后面去。10的幂有一个性质，我用程序打出来估计就很显然了。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	printf("%lf\n", pow(10, 0.23));
	printf("%lf\n", pow(10, 1.23));
	printf("%lf\n", pow(10, 2.23));
	printf("%lf\n", pow(10, 3.23));
}
```

输出是这样的：

```
1.698244
16.982437
169.824365
1698.243652
```

所以我们把 $n^k$ 和 $10^w$ 画上等号我们想办法把w求出来就可以得到一个小数，然后知道了上面那个性质以后我们就可以只取w的小数部分然后再乘上100就是前三位的数字了。

那么现在就想怎么才可以把w求出来，这个就是高中知识了

$n^k=10^w$

$log_{10}^{n^k}$ = $log_{10}^{10^w}$

$klog_{10}^{n}=w$

这不就求出来了吗，然后取w的小数部分搞一搞就出来了。

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000;

int _, cas;
long long n, k;

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: ", ++cas);
		double x = fmod(k*log10(n), 1);
		printf("%03lld %03lld\n", (long long)(pow(10,x)*100), qpow(n, k));
	}
}
```

