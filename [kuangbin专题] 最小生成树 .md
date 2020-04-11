## Jungle Roads

[POJ - 1251](https://vjudge.net/problem/POJ-1251/origin)

题意：很多地方之间需要通路，每两个点之间有K种修路方案，每种方案成本不一定相同，求这些地点互通最小成本

思路：将这些边都存起来，然后从小到大排序，让成本小的优先选择，然后把连接起来的地点加入并查集，当所有的边都加入之后答案就出来了。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, fa[30];
struct node {
	int u, v, w;
} line[100];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 0;i < 29; i++) fa[i] = i;
		int k = 0;
		for(int tt = 0;tt < n-1; tt++) {
			char fir, sec;
			int mon, num;
			scanf(" %c %d", &fir, &num);
			while(num--) {
				scanf(" %c %d", &sec, &mon);
				line[++k].u = fir-'A'+1;
				line[k].v = sec-'A'+1;
				line[k].w = mon;
			}
		}
		sort(line+1, line+1+k, cmp);
//		for(int i = 1;i <= k; i++) cout << line[i].w << " ";		
		int ans = 0, cnt = 1;
		for(int i = 1;i <= k; i++) {
			int u = find(line[i].u);
			int v = find(line[i].v);
			if(u == v) continue;
			fa[u] = v;
			ans += line[i].w; 
			cnt++;
			if(cnt == n) break;
		}
		
		printf("%d\n", ans);
	}
}
```

