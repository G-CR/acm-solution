## Sigma Function LightOJ - 1336 (唯一分解定理，因数之和性质)

题意：给一个n，输出 $[1,n]$ 中每一个数的因数之和为偶数的数的个数之和。

思路：

方法一：打表找规律

打表代码

```cpp
#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	for(int k = 1;k <= n; k++) {
		long long sum = 0;
		for(int i = 1;i <= sqrt(k); i++) {
			if(k%i==0) {
				sum += i;
				if(i != k/i) sum += k/i;
			} 
		}
		printf("%d %d\n", k, sum%2==0);
	}
}
```

通过对1000（或者100）以内就可以发现因数之和为奇数的数一般都是平方数或者是平方数的两倍，就可以写代码了。

方法二：

通过唯一分解定理的一个性质可以知道一个数的因数之和为

$f(x) = (p1^0+p1^1+p1^2+...+p1^{a1})*(p2^0+p2^1+p2^2+...+p2^{a2})*...*(pn^0+pn^1+pn^2+...+pn^{an})$

我们要使这个数为奇数需要什么条件，当然是要把括号里面的每一项都凑成奇数，这样 $f(x)$ 才为奇数那么怎么样才可以成为奇数呢；由于所有的p都是质数，那么当然需要分类思考一下2跟其他质数，可以知道2的多少次幂都是偶数然后加上最前面的1就变成了奇数，所以x的因数里面有2是不影响x的因数为奇数的；其次再来看一下其他的质数，除去最前面的1，$ai$ 必须为偶数才可以为偶数，再加上1的话就为奇数，如果所有的 $ai$ 都为偶数，那么是不是可以分为两份，也就是x是一个平方数，并且有前面可以知道这个数有2这个因数的话也是没得影响的，所以为平方数的2次幂倍都是可以的，也就得到了之前打表的结论。代码很简单。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, cas;
long long n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		printf("Case %d: ", ++cas);
		printf("%lld\n", n-(long long)sqrt(n)-(long long)(sqrt(n/2)));
	}
}
```

