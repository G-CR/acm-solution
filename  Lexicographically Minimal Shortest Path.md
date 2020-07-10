[2020, XIII Samara Regional Intercollegiate Programming Contest](https://codeforces.com/gym/102569/problem/D)

题意：给一个无向无权图，n个点，m条边。每条边上面都会有一个字母，现在从起点1开始走，走到终点n，需要你求出走过边形成的字典序最小的字符串，并且输出经过的点。

思路：首先需要想到的是如果要求字典序最小那么肯定优先让字符串的长度达到最小， "zz" 肯定比 "aaaaaa" 优先考虑。意思也就是要先让 1-> n 的距离保持在最小，然后再从这些距离同为最小的路径中选取字典序最小的那一条。

由于没有边权，所以可以把每条边的长度都视为1，这样我们就可以用BFS在O(m)的时间找出n点到剩下所有点的距离，也就是n到所有点需要经过多少个字母。用dis数组保存n到剩下所有点的距离，那么 dis[1] 应该就是所有候选的路径的字符串长度，多一个也不行，也不可能比这个更少。

然后我们是不是已经把字符串的长度定下来了，那么就可以再次从1开始遍历他的后继点。第一次遍历我们需要把从1到他的所有后继点的最小的字母选出来，然后进行第二次遍历，把从1到他的所有后继点的边上为这个最小字母的保存起来，并且记录下来每一个点的前驱为1。这样1到他的所有后继点的查找就完毕了；然后开始把刚才保存的那些点作为第一步的1，开始找这些点与他们后继点的最小字母，再遍历一次后继点找到所有与后继点边上字母为最小字母的那些点，这样一只重复下去就可以找到n点了。

需要注意一点的是找出来的后继节点中需要进行一次去重，因为可以容易想到，两个不同的点的后继点为同一个，又刚好这两条边都是符合条件的最小字母，这样就可以避免超内存的错误。

``` cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, dis[200005];
vector <pair<int, char> > g[200005];
int pre[200005];

void bfs() {
	bool vis[200005]; memset(vis, 0, sizeof(vis));
	queue <int> q; while(!q.empty()) q.pop();
	q.push(n); vis[n] = 1; dis[n] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto i: g[now]) {
			int t = i.first;
			if(vis[t]) continue;
			vis[t] = 1;
			dis[t] = dis[now]+1;
			q.push(t);
		}
	}
}

char findm(vector <int> fa) {
	char minc = 'z';
	for(auto i: fa) {
		for(auto j: g[i]) {
			int jf = j.first; char js = j.second;
			if(dis[i] == dis[jf]+1) {
				minc = min(minc, js);
			}
		}
	}
	return minc;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; ++i) {
		int u, v; char c;
		scanf("%d %d %c", &u, &v, &c);
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	
	bfs();
	
	vector <int> fa; fa.push_back(1);
	string ans = ""; pre[1] = -1;
	for(int floors = 1;floors <= dis[1]; floors++) {
		ans += minc;
		vector <int> tmp; tmp.clear();
		for(auto i: fa) {
			for(auto j: g[i]) {
				int jf = j.first; char js = j.second;
				if(dis[i] == dis[jf]+1 && js == minc) {
					if(pre[jf]==0) pre[jf] = i;
					tmp.push_back(jf);
				}
			}
			
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		fa = tmp;
	}
	int k = n;
	vector <int> res;
	while(k!=-1) {
		res.push_back(k);
		k = pre[k];
	} 
	int cnt = res.size()-1;
	printf("%d\n", cnt);
	for(int i = cnt;i >= 0; i--) printf("%d ", res[i]); puts("");
	cout << ans << endl;
}
```

