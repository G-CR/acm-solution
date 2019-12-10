题目链接：https://vjudge.net/contest/347789#problem/D


![题面](https://github.com/G-CR/acm-solution/blob/master/D%20-%20Ice%20Cream%20Tower.jpg)

​		题意：一个人很喜欢吃冰淇凌，他想要把N个冰淇凌球堆成高为K的冰淇凌球塔，但是为了稳定，下面的冰淇凌球的尺寸要大于等于它紧挨着的上面的冰淇凌球的两倍。然后要求这N个冰淇凌球最多可以组成多少个高为K的冰淇凌球塔。

​		假思路：首先会想到用贪心来堆冰淇凌球，先选择一个最大的当作最底层的，然后开始枚举或者二分查找下一个小于或等于它一般尺寸的冰淇凌球，一直找啊找下去，直到满足K，然后再开始第二轮。这个看似很好的思路其实还是有BUG的。 请看下面这个例子：

> K = 3
>
> 1	1	2	2	5	10

​		这个例子用上面的思路得到的答案就是 只能堆1个冰淇凌塔 就是 2 5 10。 但是其实正解有两个分别是1 2 10 和 1 2 5。所以这个思路不行（从前往后找也一样，或者从前往后找一遍，再从后往前找一遍取MAX 也不行, 看这个例子：1 1 2 4 8 9，K = 3）。



正确思路： 二分找答案， 然后再用贪心来验证。

​		二分： 这个题目的答案总会在(0,n/k)之间，每一次对算出的mid进行验证，如果符合要求那么区间左边更新为mid，如果不符合要求，区间右边就更新为mid-1。直到L >= R为止。

​		验证：可能的答案值数量 = n。   用一个新的数组存入前n个冰淇凌球的尺寸，每n个冰淇凌分为一组当作一个间隔，通过对原数组的遍历如果该位置满足 b[pos] >= 2*a[i-n] 那么就将a[i]的值更新为原数组的值，这样对应每组中的对应位置就是同一个冰淇凌球塔。如果中途原数组已经更新到最后一个元素还没有堆满n个冰淇凌球塔，那么这个答案就是错的，没用完或者刚好用完就证明这个答案合法，可以更新。

​		代码表述更加清晰一些:

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, k;
ll a[300005], b[300005];

bool judge(int x) { // 判断答案是否合法
	for(int i = 1;i <= x; i++) {
		a[i] = b[i];
	}
	
	int pos = x+1;
	for(int i = x+1;i <= x*k; i++) {
		while(pos <= n && a[i-x]*2 > b[pos]) pos++;
		if(pos == n+1) return 0;
		a[i] = b[pos]; pos++;
	}
	return 1;
}

int find(int l, int r) { // 通过二分查找答案
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(judge(mid)) l = mid;
		else r = mid-1;
	}
	return l;
}

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &b[i]);
		}
		sort(b+1, b+1+n);
		int ans = find(0, n/k);
		printf("Case #%d: %d\n", p, ans);
	}
}
```

