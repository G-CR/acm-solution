[C. Yet Another Counting Problem](https://codeforces.com/contest/1342/problem/C)

题意：给两个数a、b， 再给 q 个范围 l、r，问在 l～r 的范围中有多少个数x是 **x % a % b != x % b % a** ，输出符合条件的数的个数

思路：一个连续区间去模同一个数是周期性的，比如1～10 去%3 得到的结果就是 1 2 0 1 2 0 1 2 0 1 

所以题面给的a、b同样具有这样的周期性，把a * b看成一个数，那么[l ~ r] % (a * b) 的周期就是a * b了。我们需要把这个周期里面 **x % a % b != x % b % a** 的数统计起来，然后乘以周期数是不是就可以得到 [l, r] 内所有符合条件的数了？ 利用前缀和来求，最后没有满一个周期也但是满足条件的数才好加进来。

```cpp
#include <bits/stdc++.h>
using namespace std;

int pre[100000];
int _, a, b, q;
long long l, r;

long long cal(long long num, int n) {
	return pre[n-1] * (num/n) + pre[num%n];
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &a, &b, &q);
		int n = a*b;
		for(int i = 1;i < n; i++) {
			pre[i] = pre[i-1];
			if(i%a%b != i%b%a) pre[i]++;
		}
		while(q--) {
			scanf("%lld %lld", &l, &r);
			printf("%lld ", cal(r, n)-cal(l-1, n));
		}
		puts("");
	}
}
```

