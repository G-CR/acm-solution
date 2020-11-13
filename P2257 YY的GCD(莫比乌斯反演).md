[题目链接](https://www.luogu.com.cn/problem/P2257)

题意：求 $\sum_{i=1}^{n} \sum_{j=1}^{m} [gcd(i,j) == prime] $

思路：

设 $f(d)$ 为 $gcd(x,y) == d$ 的个数， $F(n)$ 为 $gcd(x,y) == n$ 和 $n$ 的倍数的个数 ( $x \in [1, n]$  $y \in [1,m]$ ) 

这样的话这两个式子的关系是这样的 $F(n) = \sum_{n|d} f(d)$ 

题目的表达式可以变成这样：$\sum_{p\in prime}\sum^{n}_{i=1}\sum^{m}_{j=1}[gcd(x,y)==1]$ 

根据假设可以变换成：$\sum_{p\in prime} f(p)$

根据莫比乌斯反演( $f(n) = \sum_{n|d} mu(\frac{d}{n})F(d) $ ) 可以转换 $f(p)$ ：$\sum_{p\in prime} \sum_{p|d} mu(\frac{d}{p})F(d)$

把枚举的 $d$ 换成 $\frac{d}{p}$ 这样式子就变成：$\sum_{p\in prime} \sum_{d=1} ^{min(\frac{n}{p},\frac{m}{p})} mu(d)F(dp)$ 

将dp替换为T: $\sum_{p\in prime} \sum_{T=1} ^{min(n,m)} mu(\frac{T}{p})F(T)$ 

求和符号换个顺序：$\sum_{T=1}^{min(n,m)} \sum_{p|T and p\in prime} mu(\frac{T}{p})F(T)$

这样就可以把$F(T)$ 提出来得到：$\sum_{T=1}^{min(n,m)}F(T) \sum_{p|T \\ p\in prime} mu(\frac{T}{p})$

即： $\sum_{T=1}^{min(n,m)} \lfloor \frac{n}{T} \rfloor \times \lfloor \frac{m}{T} \rfloor \sum_{p|T \\ p\in prime} mu(\frac{T}{p})$

用整除分块搞出每一块的值，预处理莫比乌斯函数的前缀和当作这一块的权值。

处理莫比乌斯函数的时候枚举质数，下标为质数的i倍的mu值就是mu[i] 的值，这个从式子里很好看得出，然后求一个前缀和当作整除分块的一整块的权值就可以了。$O(n)+T*O(\sqrt{n})$ 

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool check[MAX+10];
int prime[MAX+10], g[MAX+10], mu[MAX+10], sum[MAX+10];
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
	
	for(int i = 0;i < tot; i++) {
		for(int j = 1; j * prime[i] <= MAX; j++) {
			g[j * prime[i]] += mu[j];
		}
	}
	for(int i = 1;i <= MAX; i++) sum[i] = sum[i-1] + g[i];
}

int _, n, m;

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		int k = min(n, m), i, j;
		long long ans = 0;
		for(i = 1;i <= k; i = j+1) {
			j = min(m/(m/i), n/(n/i));
			ans += ((long long)(n/i) * (long long)(m/i)) * (sum[j] - sum[i-1]);
		}
		printf("%lld\n", ans);
	}
}
```

 

