## [C. Equal Sums](https://codeforces.com/contest/988/problem/C)

题意：给你k个整数序列，在这k个序列中选两个出来，每个序列减去一个数（需要在不同的位置），使得这两个序列所有数的和相等。如果有这种情况的话，输出“YES”，并且说明两个序列在第几个，分别删掉第几个数；不能满足要求的输出“NO”

思路：很容易想到的就是对每个序列求和后，从删除第一个序列的第一个开始，更新和的大小；接着从第二个序列第一个数开始删除，看和的大小是否匹配第一个序列的和；不匹配的话就删除第二个数这样一直搞下去，肯定是不行的；

再咋样时间复杂度也要控制在nlogn；那么换个角度，我能不能把我之前操作删除的那些情况都给保存起来，当我遍历后面的时候，删到了某一个序列的某一个数的时候，这个序列的和 我在之前的操作刚好也遇见过，再验证删除的这个位置跟之前删除的位置是否一样，如果不一样那么答案就出来了，那么保存操作需要用到map，这里面肯定要存删除后的和，删除的哪一个序列，删除序列中数的位置这三样参数。遍历是O(n) ，map查询效率是O(logn)。可以A的。

```cpp
#include <bits/stdc++.h>
using namespace std;

map <long long, pair<int, int> > mp;
int k, n, a[200005];

int main() {
	scanf("%d", &k);
	for(int i = 1;i <= k; i++) {
		long long sum = 0;
		scanf("%d", &n);
		for(int j = 1;j <= n; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		
		for(int j = 1;j <= n; j++) {
			long long t = sum-a[j];
			if(mp.find(t) == mp.end()) {
				mp[t] = make_pair(i, j);
			}
			else {
				if(i != mp[t].first) {
					puts("YES");
					printf("%d %d\n", mp[t].first, mp[t].second);
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
		
	}
	puts("NO");
}
```



## [D. Points and Powers of Two](https://codeforces.com/contest/988/problem/D)

题意：给你一个长度为n的序列，从这里面找一些数，这些数两两之间的差值都是2的整数幂，求最多可以找到多少个这样的数，输出个数 和 每一个数。

思路：

每个数自身与自身的差距就是 2<sup> 0</sup>的差距，所以答案最少就是1个；

两个数之间 就是差距 2<sup>x</sup>  的差距，这个也好理解；

三个数之间：a、b、c ；b-a = 2<sup>x</sup>  c-b = 2<sup>y</sup>  => c-a = 2<sup>x</sup> + 2<sup>y</sup>  ; 那么c-a这个数是不是2的整数次幂呢，其实想一想也不难发现 2<sup>1</sup> + 2<sup>1</sup> = 2<sup>2</sup> 、2<sup>2</sup> + 2<sup>2</sup> = 2<sup>3</sup>；换言之，当 **x = y** 的时候这种情况还是可以成立的；

四个数之间：就是上面的情况加入一个最大的d，然后d - c = 2<sup>z</sup> => d-a = 2<sup>x</sup> + 2<sup>y</sup> + 2<sup>z</sup> 那么这三个数相加能组成2的整数次幂吗，应该是找不到的。因为这三个数都是2的整数次幂，所以这三个数肯定是6的倍数，那么就是3的倍数，那么就肯定不能，2的整数幂咋可能有2以外数组成呢？

更多的数就不用说了，他们永远跨不过四个数之间的那道坎。

有了这个结论就很好做啦，因为数据范围放在那里的，两个数之间的差距就是[1,1e9]之间的2的整数次幂。那么枚举这些数，然后遍历每个数，通过二分查找的方式查询数组中是否有 a[i]-k 和 a[i]+k 的数存在，然后根据有没有更新答案就可以了。时间复杂度 O(30 * n * 2 * logn)，4秒可以过的。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
vector <long long> res, t;
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	res.push_back(a[1]);
	
	long long lar = (long long)2<<30;
	for(long long k = 1;k <= lar; k <<= 1) {
		for(int i = 1;i <= n; i++) {
			t.clear();
			bool left = binary_search(a+1, a+1+n, a[i]-k);
			bool right = binary_search(a+1, a+1+n, a[i]+k);

			t.push_back(a[i]);
			if(left && right) {
				t.push_back(a[i]-k);
				t.push_back(a[i]+k);
			} 
			else if(left) t.push_back(a[i]-k);
			else if(right) t.push_back(a[i]+k);
			
			if(t.size() > res.size()) {
				res.clear();
				for(int j = 0;j < t.size(); j++) res.push_back(t[j]);
			}
		}
	}
	printf("%d\n",(int)res.size());
	for(int i = 0;i < res.size(); i++) printf("%lld ", res[i]);
}
```

