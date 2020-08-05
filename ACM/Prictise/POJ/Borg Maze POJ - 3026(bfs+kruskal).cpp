#include <iostream>
#include <queue>
using namespace std;

const int N = 505, M = N*N;
int _, n, m, dis[N][N], mp[N][N], num;
char s[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct point {
	int x, y, step;
	point(int x, int y, int step): x(x), y(y), step(step) {}
};

void bfs(int stax, int stay, int stanum) {
	bool vis[N][N]; memset(vis, 0, sizeof(vis));
	queue <point> q; while(!q.empty()) q.pop();
	q.push(point(stax, stay, 0));
	vis[stax][stay] = 1;
	while(!q.empty()) {
		point head = q.front(); q.pop();
		
		for(int i = 0;i < 4; i++) {
			int tx = head.x + dx[i];
			int ty = head.y + dy[i];
			if(!vis[tx][ty] && tx >= 0 && tx < m && ty >= 1 && ty <= n && mp[tx][ty] != -1) {
				if(mp[tx][ty]) {
					dis[stanum][mp[tx][ty]] = dis[mp[tx][ty]][stanum] = head.step+1;
				}
				vis[tx][ty] = 1;
				q.push(point(tx, ty, head.step+1));
			}
		}
	}
}

int prim() {
	bool isin[M];
	int lowcost[M], clostst[M];
	isin[1] = 1;
	for(int i = 1;i <= num; i++) {
		if(i != 1) {
			lowcost[i] = dis[1][i];
			clostst[i] = 1;
			isin[i] = 0;
		}
		else lowcost[i] = 0;
	}
	
	for(int i = 1;i <= num; i++) {
		int temp = 10000000;
		int t = 1;
		for(int j = 1;j <= num; j++) {
			if(!(isin[j]) && (lowcost[j] < temp)) {
				t = j;
				temp = lowcost[j];
			}
		}
		
		if(t == 1) break;
		isin[t] = 1;
		for(int j = 1;j <= num; j++) {
			if(!(isin[j]) && (dis[t][j] < lowcost[j])) {
				lowcost[j] = dis[t][j];
				clostst[j] = t;
			}
		}
	}

	int ans = 0;
	for(int i = 1;i <= num; i++) ans += lowcost[i];
	return ans;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &m, &n);
		gets(s[0]);
		queue <point> qu; while(!qu.empty()) qu.pop();
		num = 1;
		for(int i = 1;i <= n; i++) gets(s[i]);
		for(int i = 1;i <= n; i++) {
			for(int j = 0;j < m; j++) {
				if(s[i][j] == 'S') mp[i][j] = 1;
				else if(s[i][j] == 'A') mp[i][j] = ++num;
				else if(s[i][j] == '#') mp[i][j] = -1;
				else mp[i][j] = 0;
				if(mp[i][j] > 0) {
					qu.push(point(i, j, mp[i][j]));
//					cout << "i = " << i << " j = " << j << " mp[i][j] = " << mp[i][j] << endl;
				}
			}
		}
//		cout << "qu.size = " << qu.size() << endl;
		while(!qu.empty()) {
			point t = qu.front(); qu.pop();
			bfs(t.x, t.y, t.step);
		}
		printf("%d\n", prim());
	}
}