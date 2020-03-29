[题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=4786)

题意：给N个点，M条边，边权只有 0（黑） 或者 1（白），问能否用这些边组成的生成树🌲的值属于 斐波那契数（1、2、3、5、8 ......）

思路：因为边权只有 0 和 1，所以可以组成的生成树的范围一定介于 **最小生成树** 与 **最大生成树** 之间。举个例子，已经得到了最小生成树，现在需要找第二小的生成树，那么就把最小生成树中的边权为 1 的边换成 0 就可以得到第二小的，第三小的同理。

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int u, v, c;
} node[200005];
int n, m, t, father[100005], fib[100005];

bool cmp1(Node a, Node b) {
	return a.c < b.c;
}

bool cmp2(Node a, Node b) {
	return a.c > b.c;
}

int find(int x) {
	if(x == father[x]) return x;
	return father[x] = find(father[x]);
}

int kru() {
	for(int i = 1;i <= n; i++) father[i] = i;
	int sum = 0, cnt = 0;
	for(int i = 1;i <= 2*m; i++) {
		int u = find(node[i].u);
		int v = find(node[i].v);
		if(u != v) {
			father[u] = v;
			cnt++;
			sum += node[i].c;
		}
		if(cnt == n-1) return sum;
	}
	return 0;
}

int fibinit() {
	fib[1] = 1; fib[2] = 2;
	for(int i = 3;; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > 100000) return i;
	}
}

int main() {
	int fibcount = fibinit(); 
	scanf("%d", &t);
	for(int p = 1;p <= t; p++) {
		scanf("%d %d", &n, &m);
		int num = 0, a, b, value;
		for(int i = 1;i <= m; i++) {
			scanf("%d %d %d", &a, &b, &value);
			node[++num].u = a;
			node[num].v = b;
			node[num].c = value;
			
			node[++num].u = b;
			node[num].v = a;
			node[num].c = value;
		}
		printf("Case #%d: ", p);
		sort(node+1, node+1+num, cmp1);
		int ans1 = kru();
		
		sort(node+1, node+1+num, cmp2);
		int ans2 = kru();
//		cout << "ans1 = " << ans1 << " ans2 = " << ans2 << endl;
		bool ok = 0;
		for(int i = 1;i <= fibcount; i++) {
			if(ans1 <= fib[i] && fib[i] <= ans2) {
				ok = 1;
				break;
			}
		}
		
		if(ok) puts("Yes");
		else puts("No");
	}
}
```

