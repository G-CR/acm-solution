[题目链接](http://codeforces.com/contest/1325)

**A - EhAb AnD gCd**

题意：给你一个数x，求两个数a、b，使得a，b的 **最大公约数** 和 **最小公倍数** 之和等于x。

思路：草稿纸上画一画就知道可以由 1 和 x-1组成

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, x;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &x);
		printf("1 %d\n", x-1);
	}
}
```



**B - CopyCopyCopyCopyCopy**

题意：给定一个序列，如果可以将这个序列无限次的复制本身加到序列后面，求可以得到最长的上升子序列的长度。

思路：原串取最小的，复制一次之后取次小的以此类推，并且去掉大小相同的元素即可。

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n, x;
set <int> st;

int main() {
	scanf("%d", &_);
	while(_--) {
		st.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			st.insert(x);
		}
		printf("%d\n", (int)st.size());
	}
}
```



**C - Ehab and Path-etic MEXs**

题意：给定一个含有n个节点的树，将这棵树上的边加上序号，序号添加规则需要遵循以下规则：

1、编号为 0 ～ n-2 

2、所有编号互不相同

3、MEX(u, v) 最小

MEX(u, v) 指的是 除了 u 和 v 之间的编号之外的编号。

比如样例2中 mex(3,4) 最小为 4，因为3到4之间需要经过编号3、0、2。剩下的编号就是1、4，所以最大值就是4了。

思路：

​		如果给定的树节点度都没有超过2的，可以试想，是不是有一条边可以把0、1这两个点都穿起来，那么这两个点的 mex 就是 n-2了。所以是这种情况的话无论怎么放节点结果都是一样的。

​		如果有节点度超过了3，那么就可以把0、1、2放到这个节点上的任意三个子节点上，当然不可能有一条边可以贯穿着三个点了，这样就导致了mex最大值就是2。所以做法就是把节点度超过三的标记出来，优先将0、1、2这三个点分配进去，其他的点随意即可。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int ans[100005];
vector <int> vc[100005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n-1; i++) {
		scanf("%d %d", &u, &v);
		vc[u].push_back(i);
		vc[v].push_back(i);
		ans[i] = -1;
	}
	
	int num = 0;
	for(int i = 1;i <= n-1; i++) {
		if(vc[i].size() > 2) {
			for(int j = 0;j < vc[i].size(); j++) {
				if(ans[vc[i][j]] == -1) ans[vc[i][j]] = num++;
			}
		}
	}
	
	for(int i = 1;i <= n-1; i++) {
		if(ans[i] == -1) ans[i] = num++;
	}
	
	for(int i = 1;i <= n-1; i++) printf("%d\n", ans[i]);
}
```



**D - Ehab the Xorcist**

题意：给定两个数u，v，求一个组合使得这个组合异或等于u， 求和等于v，并且要求组合中的数需要最少。

思路：

**-1 的情况：** 异或可以看作是不进位的加法也就由此得出**u <= v**，否则答案不存在；u和v的奇偶一定是相同的 v 为奇数时证明有 **奇数个奇数相加** ，那么也就说明有奇数个奇数异或，那最低位一定是 0^1 的结果 -> 也一定是奇数，偶数同理。

**0 的情况：**u = v = 0

**其他情况：** 

u = v != 0 时，u或者v本身就是答案。 

u != v时：u ^ 0 就可以保证 u，保证 v 就需要 u + 0 = v。也就是 0 = v-u，0变成两个相同的数异或就ok了 -> **(v-u)/2**，最多三个数就可以表示出来了。 But 有一种特殊情况使得 (v-u)/2 ^ ((v-u)/2 + u) = u，因为在相加的时候恰好两个数全都是 0 和 1相对的，这样再在相同的地方异或结果还是相加之前的u (比如：10101 ^ (10101+101010) = 101010)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long u, v;

int main() {
	scanf("%lld %lld", &u, &v);
	if(u > v || (v-u)%2) {
		puts("-1");
	}
	else if(u == v) {
		if(u == 0) puts("0");
		else {
			puts("1");
			printf("%lld\n", u);
		}
	}
	else {
		long long x = (v-u)/2;
		if((x&u) == 0) {
			puts("2");
			printf("%lld %lld\n", x, x+u);
		}
		else {
			puts("3");
			printf("%lld %lld %lld\n", x, x, u);
		}
	}
}
```

