[题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=4771)

**题意**：在一个 N*M 的地图中，每个格子代表一个房间，'#'代表坚不可摧的房间，是不可进入的； '.'代表脆弱的房间🏠，是可以进入的；'@'代表起点，然后有K个宝物，分别放在了这些脆弱的房间里面。求从起点开始，拿到所有宝物最小需要的步数（在起点步数为0，每走一格步数+1）

**错误思路**：需要求最短路，盲猜直接BFS，将宝物的坐标用一个map存起来，在struct里面多加一个 set 来记录当前路径中拿到了哪些宝物，当 set.size 和 k 相等的时候，直接输出答案就完事了。巴特，这个思路有一个不好处理的地方，在实际情况当中或许正解会同一个点走两次，所以我们不能在剪枝的时候加上vis数组验证，这样就会导致大量的点来回走，并且加入队列，耗费太多空间，就 Memory Limit Exceeded 了。

看看代码吧🤦‍♂️：

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y;
char mp[105][105];
map <pair<int, int>, bool> ok;
struct Node {
	int x, y, step;
	set <pair<int, int> > con;
};
queue <Node> q;

int main() {
	while(~scanf("%d %d", &n, &m) && n != 0) {
		ok.clear();
		while(!q.empty()) q.pop();
		int stax, stay;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &mp[i][j]);
				if(mp[i][j] == '@') stax = i, stay = j; 
			}
		}

		
		scanf("%d", &k);
		int num = k;
		while(k--) {
			scanf("%d %d", &x, &y);
			ok[make_pair(x, y)] = 1;
		}
		
		Node t;
		t.x = stax; t.y = stay; t.step = 0;
		if(ok[make_pair(stax, stay)] == 1) {
			t.con.insert(make_pair(stax, stay));
		}
		q.push(t);
		bool fin = 0;
		int ans = -1;
		while(!q.empty()) {
			Node res = q.front(); q.pop();
			for(int i = -1;i <= 1; i++) {
				for(int j = -1;j <= 1; j++) {
					if((i != 0 && j != 0) || (i == 0 && j == 0)) continue;
					
					int tx = res.x+i, ty = res.y+j, ts = res.step+1;
					set <pair<int, int> > tc = res.con;
					if(tx > n || tx < 1 || ty > m || ty < 1 || mp[tx][ty] == '#') continue;
					Node Push;
					Push.x = tx; Push.y = ty; Push.step = ts; Push.con = tc;
					if(ok[make_pair(tx, ty)] == 1) {
						Push.con.insert(make_pair(tx, ty));
						if(num == Push.con.size()) {
							ans = ts;
							fin = 1;
							break;
						}
					}
					
					q.push(Push);
				}
				if(fin) break;
			}
			if(fin) break;
		}
		printf("%d\n", ans);
	}
}
```

**正确思路**：为了避免上述情况，其实可以让BFS的路径按照我们自己想要的路线走；因为这道题目的K值比较小，从起点开始走完所有的点的顺序也就不多，四个宝物的走法也就是 $4 * 3 * 2 * 1$ 这么多种，这已经是最多的情况了，把这些点可能走的路线全部走一遍，因为bfs从一个点走到另一个点肯定是最短路径的，把这几段的路走的步数加起来就是一种方案，最后答案取最小的就OK了，这里面用了一个 **[全排列的函数](https://blog.csdn.net/mm114820/article/details/88059987)** ,也就是把从 1 ～ K可以走的全部方案枚举出来的函数。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, k, stax, stay;
char mp[105][105];
struct node {
	int x, y, step;
	node(int a, int b, int c): x(a), y(b), step(c){}
	node(){}
} ok[5];
int p[5];
bool meet[105][105];
int chanx[] = {-1, 1, 0, 0};
int chany[] = {0, 0, -1, 1};

int bfs() {
	queue <node> q;
	q.push(node(stax, stay, 0));
	meet[stax][stay] = 1;
	int cnt = 1;
	while(!q.empty()) {
		node t = q.front(); q.pop();
		for(int i = 0;i < 4; i++) {
			int tx = t.x + chanx[i];
			int ty = t.y + chany[i];
			int ts = t.step + 1;
			
			if(tx > n || tx < 1 || ty > m || ty < 1 || mp[tx][ty] == '#' || meet[tx][ty]) continue;
			bool flag = 0;
			if(tx == ok[p[cnt]].x && ty == ok[p[cnt]].y) flag = 1;
			if(flag) {
				while(!q.empty()) q.pop();
				memset(meet, 0, sizeof(meet));
				if(cnt == k) return ts;
				cnt++;
			}
			
			q.push(node(tx, ty, ts));
			meet[tx][ty] = 1;
			if(flag) break;
		}
	}
	return -1;
}

int main() {
	while(~scanf("%d %d", &n, &m) && n) {
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &mp[i][j]);
				if(mp[i][j] == '@') stax = i, stay = j;
			}
		}
		
		scanf("%d", &k);
		int num = 1;
		for(int i = 1;i <= k; i++) {
			scanf("%d %d", &ok[i].x, &ok[i].y);
			p[i] = i;
			num *= i;
		}
		
		int ans = -1;
		
		while(num--) {
			int sum = bfs();
//			cout << "sum = " << sum << endl;
			if(sum != -1) ans = ans == -1?sum:min(ans, sum);
			next_permutation(p+1, p+1+k);
		}
		printf("%d\n", ans);
	}
}
```

