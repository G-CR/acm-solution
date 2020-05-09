[题目链接](https://ac.nowcoder.com/acm/problem/14247)

思路：两个连续区间的异或和为0，看到区间嘛，就很容易想到前缀和处理，这个题目也差不多，前缀异或嘛，看着 n 为 1000，就直接暴力找这两个区间呗。

枚举分割点，分割点之前的所有前缀异或和相同的都累加起来，然后枚举分割点之后的疑惑和，如果有相等的（疑惑和为0其实就是相等的意思吧）那么就加上之前累加的值，这就凑成一对了，然后一直搞就出来答案了，ans记得开long long

```cpp
#include <bits/stdc++.h>
using namespace std;

int pre[1005], n, x;
map <int, int> mp;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		pre[i] = pre[i-1]^x;
	}
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 0;j < i; j++) {
			mp[pre[i]^pre[j]]++;
		}
		for(int j = i+1;j <= n; j++) {
			ans += mp[pre[j]^pre[i]];
		}
	}
	
	printf("%lld\n", ans);
}
```

