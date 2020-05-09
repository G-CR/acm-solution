[题目链接](https://ac.nowcoder.com/acm/problem/50940)

题意：给你一个数字序列，让你遍历每到奇数项的时候就输出一下前面项的中位数。输入输入也多了一些不必要的东西，称它为仪式感吧

思路：很容易想到时候每遍历一个数字就对前面的 i 项进行一次排序，这样我就可以直接输出 **a[i/2+1]** 岂不是美滋滋， $O(1000*n^2(logn)^2$ , 所以不行。我们现在需要维护的是前 i 项的中位数，那么中位数有什么特点，比前面的树都大，比后面的数都小（废话）。

所以我们在处理的时候让较大的放在一边，让较小的放在一边，这样就可以在查询的时候比较好处理了，害，优先队列呗。

搞两个优先队列，一个升序，一个降序可以这么理解：

大------------小。  。大----------小

“。”代表 优先队列的top，左边的叫q，右边的叫p，可以把这两个优先队列组合起来看成一个序列，两个top之间只不过是a[i] 与 a[i+1]，这里面肯定是排好序的罗

先将 a[1] 插入到左边的q中，然后开始遍历：

```
如果 a[i] < q.top 那么 p.push(a[i]) 因为q的整体需要比p大嘛
如果 a[i] >= q.top 那么 q.push(a[i])
在每一次插入之后，需要判断一下 q 与 p 的 size，你想呀，你输出肯定是输出top，如果两遍的top并不是在序列的中间部位，输出的肯定不是中位数，这时候就需要判断一下，让两个size之间差距不超过1，然后输出size大的那一边的top
```

$O(1000*(logn)^2)$  完事～

```cpp
#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q;
priority_queue <int, vector<int> > p;
int _, num, n, a[10000];

int main() {
	scanf("%d", &_);
	while(_--) {
		int cnt = 0;
		scanf("%d %d", &num, &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		printf("%d %d\n", num, n/2+1);
		while(!q.empty()) q.pop(); 
		while(!p.empty()) p.pop();
		for(int i = 1;i <= n; i++) {
			if((q.empty() && p.empty()) || a[i] >= q.top()) q.push(a[i]);
			else p.push(a[i]);
			while((int)q.size()-(int)p.size() > 1) {int t = q.top(); q.pop(); p.push(t);}
			while((int)p.size()-(int)q.size() > 1) {int t = p.top(); p.pop(); q.push(t);}
			if(i&1) {
				if(q.size() > p.size()) printf("%d ", q.top());
				else printf("%d ", p.top());
			}
			if(i%20 == 0) puts("");
		}
		if(_) puts("");
	}
}
```