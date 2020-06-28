[题目链接](https://acm.timus.ru/problem.aspx?space=1&num=1658)

题意：给出一个数n的 每个数位之和 s1 与 每个数位的平方之和 s2，让你求出这个数，如果有很多种答案就输出最小的那一个。 

思路：题目的输入输出中给了n的一些限制条件，n的位数不会超过100位，那么我们就可以得出每一位只之和最大也就900，每一位的平方之和最大也就8100。每一位取值1～9（0没有增加贡献还占位置），那么 s1 与 s2 就可以由上一次的 s1-k 与 s2-k*k 改变过来 (k就是枚举的1~9) ，就可以写出状态的转移方程了，$dp[i][j]$ 表示每一位的和为i，每一位的平方的和为j 所用的最小位数。

> $dp[i][j] = min(dp[i][j], dp[i-k][j-k*k]+1)$

这个时候已知s1 和 s2 情况下n的位数是多少了，那么还需要解决的就是每一位分别为多少，其实在状态转移的时候k不就是每一位的数值吗，再开一个 $pre[i][j]$ 数组记录 每一位和为i，每一位平方的和为j 最高位数字就可以了。



```cpp
#include <bits/stdc++.h>
using namespace std;

int _, s1, s2;
int dp[1000][8500], pre[1000][8500];

void init() {
	for(int i = 0;i <= 900; i++) for(int j = 0;j <= 8100; j++) 
		dp[i][j] = 101;
		
	dp[0][0] = 0;
	for(int i = 1;i <= 900; i++) {
		for(int j = 1;j <= 8100; j++) {
			for(int k = 1;k <= 9; k++) {
				if(i-k<0 || j-k*k<0) break;
				if(dp[i][j] > dp[i-k][j-k*k]+1) {
					dp[i][j] = dp[i-k][j-k*k]+1;
					pre[i][j] = k;
				}
			}
		}
	}
	
}

int main() {
	init();
//	for(int i = 1;i <= 900; i++) {
//		for(int j = 1;j <= 8100; j++) {
//			printf("%d ", dp[i][j]);
//		}
//		getchar();
//	}
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &s1, &s2);
		if(s1 > 900 || s2 > 8100 || dp[s1][s2] > 100 || pre[s1][s2] == 10) {
			puts("No solution");
			continue;
		}
		
		int l = s1, r = s2;
		while(dp[l][r]) {
			int t = pre[l][r];
			printf("%d", t);
			l -= t;
			r -= t*t;
		}
		puts("");
	}
}
```

