[比赛链接](https://ac.nowcoder.com/acm/contest/5203)

## A - 相反数

题意：给一个数n，输出它本身加上它的逆序（去掉前导〇）

思路：字符串模拟

```cpp
#include <bits/stdc++.h>
using namespace std;

string s;

int zheng(string s) {
	int t = 0;
	for(int i = 0;i < s.length(); i++) {
		t *= 10;
		t += (s[i]-'0');
	}
	return t;
}

int fan(string s) {
	int t = 0, sta;
	for(int i = s.length()-1;i >= 0; i--) {
		if(s[i] != '0') {
			sta = i;
			break;
		}
	}
	
	for(int i = sta;i >= 0; i--) {
		t *= 10;
		t += (s[i]-'0');
	}
	return t;
}

int main() {
	cin >> s;
	printf("%d\n", zheng(s)+fan(s));
}
```



## B - Music Problem

题意：给你n个数，要求这些数中能够是否选取一部分使得这些数的和是模3600为0

思路：首先想到的是01背包问题，但是看到n的大小 2<sup>1e5</sup>的复杂度就知道应该会超时。其实我们只需要知道这些数中是否有符合要求的就可以了，所以就开一个dp[i] 数组，表示在n个数中是否存在部分数之和 % 3600 等于 i 。然后只要dp[0] = 1的时候我们就可以结束程序了。怎么维护dp数组呢，就是遍历a数组的时候，遍历dp数组，如果此时dp[j]  != 0，那么就存在某种情况使得 和%3600 = j，那么加上a[i] 再 % 3600 就可以得到 dp数组另一个位置的值，一直循环就可以查证题目了。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, a[100005];
int dp[3600];
queue<int> q;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] %= 3600;
		}
		while(!q.empty()) q.pop();
		memset(dp, 0, sizeof(dp)); dp[0] = 2;
		for(int i = 1;i <= n && dp[0] != 1; i++) {
			for(int j = 0;j < 3600 && dp[0] != 1; j++) {
				if(dp[j]) {
					q.push((j+a[i])%3600);
				}
			}
			
			while(!q.empty()) {
				int t = q.front(); q.pop();
				dp[t] = 1;
			}
		}
		printf("%s\n", dp[0]==1?"YES":"NO");
	}
}
```



## C - 完全平方数

题意：查询 [l, r] 之间完全平方数的个数

思路：一个数开平方就是它所包含的完全平方数的个数，也就是大的减去小的就可以了，但是需要讨论一下小的是否是完全平方数，是的话答案+1.

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, l, r;

int main() {
	scanf("%d", &_);
	while(_--) {
		int ans = 0;
		scanf("%d %d", &l, &r);
		ans = (int)sqrt(r)-(int)sqrt(l);
		int t = sqrt(l);
		if(t*t == l) ans++;
		printf("%d\n", ans);
	}
}
```

