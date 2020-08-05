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