### [E - Count Descendants](https://atcoder.jp/contests/abc202/tasks)

#### 题意

给一棵含有n个节点并且1为根的树，有Q次询问，每次询问给一个节点序号u和一个路径长度d，需要求出从根节点出发并且经过节点u，路径长度为d的路径个数。

#### 思路：

先不管必须经过的点u，只考虑路径长度的话，那么如果此时需要求路径长度为d的答案，那么肯定是从根节点开始，所有的深度为d的节点个数，如果是这样的题面的话，就通过一次dfs遍历预处理出所有节点的深度即可。但是此时加上了必须经过u节点的要求，那么就可以想到答案就是在u的子树中，并且深度为d的所有节点。

现在问题就转化为怎么求一个节点的所有子节点，可以考虑使用dfs序。比如已知x是y的子孙节点，那么一定存在 $in_y < in_x < out_y$ 。针对这个性质，我们可以把所有处于相同深度节点的in值存储起来，然后再在这个数组中找到处于 $in_y$ 与 $out_y$ 之间的值的数量即可，这个可以使用二分来解决。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int n, dep[N], in[N], out[N];
vector <int> g[N], res[N];

int now = 0;
void dfs(int p) {
	in[p] = now++;
	res[dep[p]].push_back(in[p]);
	for(int to: g[p]) {
		dep[to] = dep[p] + 1;
		dfs(to);
	}
	out[p] = now++;
}

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		g[p].push_back(i);
	}
	dfs(1);
	
	int q; scanf("%d", &q); while(q--) {
		int u, len; scanf("%d %d", &u, &len);
		auto x = lower_bound(res[len].begin(), res[len].end(), out[u]);
		auto y = lower_bound(res[len].begin(), res[len].end(), in[u]);
		
		printf("%d\n", (int)(x - y));
	}
}
```

