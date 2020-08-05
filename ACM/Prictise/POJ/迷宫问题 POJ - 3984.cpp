#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int x, y;
	vector< pair<int, int> >vc;
}node, t;
queue <Node> q;

int mp[5][5], vis[5][5];

void bfs() {
	while(!q.empty()) {
		node = q.front(); q.pop();
		if(node.x == 4 && node.y == 4) {
			int n = node.vc.size();
			for(int i = 0;i < n; i++) {
				printf("(%d, %d)\n", node.vc[i].first, node.vc[i].second);
			}
		}
		for(int i = -1;i <= 1; i++) {
			for(int j = -1;j <= 1; j++) {
				if(i != 0 && j != 0) continue;
				if(node.x+i > 4 || node.x+i < 0 || node.y+j > 4 || node.y+j < 0) continue;
				if(mp[node.x+i][node.y+j] == 0 && !vis[node.x+i][node.y+j]) {
					vis[node.x+i][node.y+j] = 1;
					t.x = node.x+i; t.y = node.y+j;
					t.vc = node.vc; t.vc.push_back(make_pair(t.x, t.y));
					q.push(t);
				}
			}
		}
	}
}

int main() {
	for(int i = 0;i < 5; i++) {
		for(int j = 0;j < 5; j++) {
			scanf("%d", &mp[i][j]);
		}
	}
	
	vis[0][0] = 1;
	node.x = 0; node.y = 0;
	node.vc.push_back(make_pair(node.x, node.y));
	q.push(node);
	
	bfs();
}