## [C - Alphabetic Removals](http://codeforces.com/contest/999/problem/C)            

**题意**：给一个字符串，从左边开始删除第一个'a'，第二个'a'... 一直删到没有，再从左边开始删除第一个'b'，第二个'b' 这样以此类推，给定字符串的长度和需要删除字符的数量。

**思路**：直观一点的思路就是把 a～z 的的坐标分类整理好，存在一个二维vector里面，然后按顺序把这些坐标标记删除就好了。但是在删除的过程中奈何 erase 函数复杂度感人，奈何自己想不出其他的数据结构来感化他，这个思路就停在了 n <sup>2</sup> 

硬杠不行就换个方式呗，其实可以把上面的思路用自己的方式模拟出来，知道k的大小，我们O（n）遍历看需要把'a'以前的字母全部删掉，还是把'b'以前的字母全部删掉，知道大范围就再精确小范围，删到'a'的第几个，或者删到'b'的第几个。

超时代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

vector <int> vc[30];
int n, k;
string s;
bool vis[400005];

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0;i < n; i++) {
		vc[s[i]-'a'].push_back(i);
	}
	
	for(int i = 0;i < 26; i++) {
		while(!vc[i].empty() && k) {
			vis[vc[i][0]] = 1;
			vector<int>::iterator it = vc[i].begin();
			vc[i].erase(it);
			k--;
		}
		if(!k) break;
	}
	for(int i = 0;i < n; i++) {
		if(!vis[i]) printf("%c", s[i]);
	}
	puts("");
}

```



正确代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int num[30];
int n, k;
string s;

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0;i < n; i++) {
		num[s[i]-'a']++;
	}
	char t = '`';
	int kan = 0;
	for(int i = 0;i < 26; i++) {
		if(kan + num[i] >= k) {
			kan = k-kan;
			t++;
			break;
		}
		else {
			kan += num[i];
			t++;
		}
	}
	
	for(int i = 0;i < n; i++) {
		if(s[i] > t) {
			printf("%c", s[i]);
		}
		if(s[i] == t) {
			if(kan) kan--;
			else printf("%c", s[i]);
		}
	}
	puts("");
}
```



## [E - Reachability from the Capital](http://codeforces.com/contest/999/problem/E)

题意：有n个城市，m条单向路。有一个中心城市，目的是要让这个中心城市可以直接或者间接得到达所有其他的城市，间接到达就是 a->b, b->c 那么 a->c了。问还需要建设多少条道路才可以实现中心通所有。

思路：我们首先可以把已经和中心城市连通的城市标记起来，然后再遍历所有的城市，当遍历到与中心城市不连通的城市时，我们再次遍历这个城市，看他能够到达的城市有几个，这样我们就得到了一个 不与 中心城市连通的城市 可以到其他城市数量 的集合。

有点拗口，举个例子:拿样例一来看：1为中心城市，可以到达城市 2、3、5、6、8。剩下的不与1连通的城市为 4、7、9，他们分别可以到达城市的数量是 1、1、1。

然后我们通过对这个数量进行降序排序，因为可以到达更多城市的城市 连接 主城市之后 后面很多到达很少城市的城市 就不需要再连接了（算是贪心吧），连接之后把这些城市打上标记，答案+1就👌

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, s, cnt;
vector <int> g[5005];
bool vis[5005], ok[5005];

void dfs1(int u) {
	ok[u] = 1;
	for(auto to: g[u]) {
		if(!ok[to]) dfs1(to);
	}
}

void dfs2(int u) {
	vis[u] = 1;
	++cnt;
	for(auto to: g[u]) {
		if(!ok[to] && !vis[to]) dfs2(to);
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &s); s--;
	int u, v;
	for(int i = 0;i < m; i++) {
		scanf("%d %d", &u, &v); u--; v--;
		g[u].push_back(v);
	}
	
	dfs1(s);
	
	vector<pair<int, int> > val;
	for(int i = 0;i < n; i++) {
		if(!ok[i]) {
			cnt = 0;
			memset(vis, 0, sizeof(vis));
			dfs2(i);
			val.push_back(make_pair(cnt, i));
		}
	}
	
	sort(val.begin(), val.end());
	reverse(val.begin(), val.end());
	
	int ans = 0;
	for(auto it: val) {
		if(!ok[it.second]) {
			ans++;
			dfs1(it.second);
		}
	}
	
	printf("%d\n", ans);
}
```

