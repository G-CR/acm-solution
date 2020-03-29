[题目链接](https://zoj.pintia.cn/problem-sets/91827364500/problems/91827369571)

**题意** ：一个打印店中有这样一个优惠政策：当打印的纸张达到一个值的时候，所有的纸都按照符合当前纸张数量的价格来定价。给出优惠政策的具体数据和几个打印数量，求出每次打印最少需要多少钱。

**思路** ：纸张单价是打印数量越多越便宜，所以可能会有一种情况就是我打印的更多，但是我出的钱或许更少；由此我们需要从后遍历一次，将每个刚好达到优惠门槛的纸张数量进行比较，那些打印纸张少但是总价更贵的 就由 后面纸张多但是总价便宜的价格代替；这样就保证了优惠力度最大。之后就是需要将 **输入的纸张数量** 与 题目给的 **优惠门槛纸张数量** 对比，找到可以打折的最大纸张数量，对应与预处理好的价格表输出就可以了。

```cpp
#include <iostream>
using namespace std;

int _, n, m;
long long s[100005], p[100005], now[100005], q;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &s[i], &p[i]);
		}
		
		long long minn = 1e18;
		for(int i = n;i >= 1; i--) {
			minn = min(minn, s[i]*p[i]);
			now[i] = minn;
//			cout <<"! "<< now[i] << endl;
		}
		
		while(m--) {
			scanf("%lld", &q);
			if(q >= s[n]) printf("%lld\n", q*p[n]);
			else {
				int cnt = lower_bound(s+1, s+1+n, q) - s;
//				cout << "cnt = " << cnt << endl;
				
				printf("%lld\n", min(now[cnt], q*p[cnt-1]));
			}
			
		}
	}
}
```

