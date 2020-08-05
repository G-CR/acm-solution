## LightOJ - 1341 Aladdin and the Flying Carpet (唯一分解定理)

题意：给一个 **长方形** 的面积a，求有多少组整数边可以构成这样的长方形，并且每一组边的最小长度不能小于b。

思路：我的这个复杂度理论上是不能过这一道题的！处理不符合要求的因数的复杂度太大了。但是我数论太菜了没有办法给出更优的解法，希望有个大佬能发一个正确复杂度的题解。但是这道题不妨碍学一下新的知识点。

我们可以知道一个数可以分解成若干个质数相乘，并且可能会有一些相同的质数在里面，表示为  $x = p1^{a1}+p2^{a2}+...+pn^{an}$ 

那么唯一分解定理就可以得出x的因数的个数 $f(x) = (1+a1)*(1+a2)*...*(1+an)$ 

对于这道题我们就可以预处理出前 $1e6$ 个素数分别是多少（不需要再往上取了），然后针对于x把可以整除它的因数的指数求出来就可以得到x总共有多少个因数了，除以2就是没有限制的可以组成a的个数，但是现在有一个b的限制，在这里我就没有其他的好办法来减少时间了，只能 $O(n)$ 地去遍历判断，可以整除一个就答案减一。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _;
long long a, b;

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
		long long sum = 0;
		while(x%prime[i] == 0) {
			sum++;
			x /= prime[i];
		}
		ans *= (sum+1);
	}
	if(x>1) ans *= 2;
	return ans;
}

int main() {
	solve();
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &a, &b);
		printf("Case %d: ", ++cas);
		if(a < b*b) {puts("0"); continue;}
		long long ans = getfac(a);
		ans /= 2;
		for(int i = 1;i < b; i++) {
			if(a%i == 0) ans--;
		}
		printf("%lld\n", ans);
	}
}
```

