[题目链接](https://ac.nowcoder.com/acm/contest/8282/D)

求 $\sum_{i=1}^{n}\sum_{j=1}^{n}μ(ij)$

推公式：

由于积性函数的性质 当 $gcd(i,j) == 1$ 的时候 $μ(ij) = μ(i)*μ(j)$

所以式子可以变成这样：

​								$\sum_{i=1}^{n}\sum_{j=1}^{n}[gcd(i,j)==1]μ(i)μ(j)$ 

由反演性质可以将 $[gcd(i,j)==1]$ 转变为 $\sum_{k|gcd(i,j)}μ(k)$ ，式子变成：

​								$\sum_{i=1}^{n}\sum_{j=1}^{n}\sum_{k|gcd(i,j)}μ(k)μ(i)μ(j)$ 

改变枚举顺序，将枚举k提前，可以得到:

​								$\sum_{k=1}^{n}μ(k)\sum_{i=1}^{\frac{n}{k}}\sum_{j=1}^{\frac{n}{k}}μ(i*k)μ(j*k)$

再将每一项求和提出来可以变成:

​								$\sum_{k=1}^{n}μ(k)\sum_{i=1}^{\frac{n}{k}}μ(i*k)\sum_{j=1}^{\frac{n}{k}}μ(j*k)$

然后发现后两项求的是同一个东西，再稍微做一点简化:

​								$\sum_{k=1}^{n}μ(k)(\sum_{i=1}^{\frac{n}{k}}μ(i*k))^2$

这样式子是推出来了，从后面一项求和的上界可以发现随着k的变化，总会有一段区间的值是不变的，这里就可以用整除分块来优化时间，把所有的答案 $O(n\sqrt{n})$ 预处理出来，$O(1)$ 输出就好了。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4;
bool check[MAX+10];
int prime[MAX+10];
int mu[MAX+10];
int pre[MAX+10], ans[MAX+10];

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
	
	for(int i = 1;i <= MAX; i++) {
		int res = 0;
		for(int l = i, r; l <= MAX; l = r+1) {
			r = min(MAX, l+i-1);
			res += mu[l];
			ans[l] += mu[i] * res * res;
			ans[r+1] += -mu[i] * res * res;
		}
	}
	
	for(int i = 1;i <= MAX; i++) {
		ans[i] = ans[i-1] + ans[i];
	}
}

int _, n;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
}
```



