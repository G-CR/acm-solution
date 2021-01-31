[题目链接](https://www.luogu.com.cn/problem/P3052)

思路：主要讲一下模拟退火的思路。

这个题目有一个贪心的假思路，就是从大到小排个序，然后从头开始取，当大于界限的时候就放到下一堆里。这样显然构不成最优解，因为或许有一些较大的值跟较小的值恰好能凑满的话可以比贪心更优。所以就会产生较大的数在前面的组成一堆会更好，这里使用随机交换的方法，如果此次交换更优那么就更新答案，如果不，就计算接受的概率，接受的话就更新当前解，不接受的话就再换回来。参数调整好，多交几发🤦‍♂️。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, W, ans;
int w[20];
bool vis[20];

int getzu() {
	int res = 1;
	int now = 0;
	for(int i = 1;i <= n; i++) {
		if(now + w[i] > W) {
			now = w[i];
			res++;
		}
		else now += w[i];
	}
	return res;
}

void sa() {
	double T = 10000, D = 0.996;
	int cur = n;
	while(T > 1e-14) {
		int pos1 = rand() % n + 1;
		int pos2 = rand() % n + 1;
		swap(w[pos1], w[pos2]);
		int now = getzu();
		if(now < cur) {
			cur = now;
			if(ans > cur) ans = cur;
		}
		else if(exp(ans-now)/T*RAND_MAX > rand()) {
			cur = now;
		}
		else swap(w[pos1], w[pos2]);
		T *= D;
	}
}

void solve() {
	int num = 500;
	while(num--) {
		sa();
	}
}

int main() {
	srand(time(NULL));
	scanf("%d %d", &n, &W);
	ans = n;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &w[i]);
	}
	solve();
	
	printf("%d\n", ans);
}
```

