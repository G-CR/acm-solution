[比赛链接](https://ac.nowcoder.com/acm/contest/5678)

## A - 拯救咕咕咕之史莱姆

思路：害，这题意理解岔了，在写代码之前一直在推第i天的伤害，也没想错，但是想多了，怪不得他们A的这么快！说一说咋想的吧。

首先，每一天的伤害都是由小洞和大洞一起提供的，不论大小都会减少史莱姆3点HP，所以我们需要把每一天有多少个大洞和小洞求出来也可以得到第i天的伤害了，最后弄一个前缀和就可以 O(1) 求出前 i 天的伤害。

![IMG_1675(20200523-225606)](/Users/gongzhaorui/Downloads/IMG_1675(20200523-225606).JPG)

看一下推导图，从第五天开始

当天的大洞的个数等于 **前一天的大洞个数 + 三天前刚刚出现的小洞个数** 

当天的小洞个数等于 **前一天的小洞个数 - 三天前的小洞个数 + 前一天大洞个数 * 2**  

就可以求出第 i 天一共有多少个洞了。剩下的模拟就可以了，~~虽然最后只需要前五天的数据~~

```cpp
#include <bits/stdc++.h>
using namespace std;

long long big[100], small[100], hp;

void init() {
	big[1] = 1; small[1] = 0;
	big[2] = 1; small[2] = 2;
	big[3] = 1; small[3] = 4;
	big[4] = 1; small[4] = 6;
	for(int i = 5;i <= 100; i++) {
		big[i] = big[i-1]+(small[i-3]-small[i-4]);
		small[i] = small[i-1] - (big[i]-big[i-1]) + big[i-1]*2;
	}
}

int main() {
	init();
	long long sum = 0;
	for(int i = 1;i <= 5; i++) {
		sum += (big[i]+small[i]) * 3;
	}
	while(~scanf("%lld", &hp) && hp) {
		if(hp <= sum) puts("AOLIGEI!");
		else puts("DAAAAAMN!");
	}
}
```



## E - 无敌阿姨

思路：这题也出的太真实了，最近学校一说不开学了，很多人就开始想办法联系宿管，联系快递想把学校的东西都弄回来。这题就是模拟，题目已经规定死了，从最底层开始搬被子，没让你自由发挥，空着手跑上跑下，就为了省一个k，可能也就我一个人这么理解题意了，还想来一手贪心。这个题目就注意一点点细节就可以了，我的写法就是在阿姨能不能上楼的条件上需要考虑一下，剩余体力是否大于k，或者是当前手中没有被子（这两个不是同一个条件），还有就是这层楼的被子搬完没有，其他的没什么。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, m, k, a[105];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		int now = 0, stair = 1, ans = 0;
		
		while(stair <= n) {
			int can = max(0, m-now); //printf("can = %d\n", can);
			now += min(can, a[stair]); //printf("now = %d\n", now);
			a[stair] = max(0, a[stair]-can); //printf("a[%d] = %d\n", stair, a[stair]);
			if((can-k > 0 || now == 0) && a[stair] == 0) {
				if(now) now += k;
				stair++;
			}
			else {
				ans++;
				now = 0;
			}
//			printf("ans = %d\n\n", ans);
//			getchar();
		}
		if(now) ans++;
		printf("%d\n", ans);
	}
}
```



## H - 中位因数

思路：题意很简单，暴力谁都会，主要是怎么优化的问题。我们需要求的就是每个数的因数的最中间的两个的平均数，比如 6 的因数是 1 2 3 6，那么最终我们需要得到的是一组2 3，来求题意中的中位数。想一下要是枚举每一个数的因数的话好像就没那么大的时间复杂度了。

怎么做得到呢，有点那种素数筛的思想在里面了，x 最大是1e6，我们就枚举因数 i 从1到1e6 ，然后第二层循环就枚举 i 的倍数，这样每次枚举出来的 j 都是可以被i整除的，所以每一次循环都是有效的，我们的目的是要找到一个数最中间的那一组数，有什么特点呢，这一组数据的较小的值是所有组的因数较小的那一边的最大的那一个。

举个例子，24的因数有 1 2 3 4 6 8 12 24 我们需要找 4 6，我们可以发现 4 是每组因数里面较小一边的最大的那一个 它比 1 24、2 12、3 8里面的 1 2 3 都要大，所以维护一个 能整出j 的最大值，就可以得到中位数了。

当然这个成立是在因数的个数为偶数的时候成立，那么为奇数的时候只有一种可能，就是它是某一个数的平方，单独讨论就可以了。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
long long f[1000006], g[1000006];
bool ok[1000006];
int mx[1000006], _;

int main() {
	for(int i = 1;i*i <= 1000000; i++) {
		int x = i*i;
		f[x] = i; ok[x] = 1;
	}
	
	for(int i = 1;i <= 1000000; i++) {
		for(int j = i;j <= 1000000; j += i) {
			if(ok[j]) continue;
			int x = i; int y = j/i;
			if(x > y) swap(x, y);
			if(mx[j] < x) {
				f[j] = (x+y)/2;
				mx[j] = x;
			}
		}
	}
	
	for(int i = 1;i <= 1000000; i++) g[i] = (g[i-1] + f[i]) % mod;
	
	scanf("%d", &_);
	while(_--) {
		int x; 
		scanf("%d", &x);
		printf("%lld\n", g[x]);
	}
}
```

