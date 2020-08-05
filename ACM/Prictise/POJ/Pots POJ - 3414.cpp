#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
	int x, y, step;
	string s;
}node, t;
int a, b, c, ans;
bool vis[101][101];
queue <Node> q;

void check() {
	if(!vis[t.x][t.y]) {
		vis[t.x][t.y] = 1;
		q.push(t);
	}
}

void bfs() {
	while(!q.empty()) {
		node = q.front(); q.pop();
		if(node.x == c || node.y == c) {
			printf("%d\n", ans = node.step);
			cout << node.s << endl;
			break;
		}
		
		if(node.x < a) {
			t.x = a; t.y = node.y; t.step = node.step+1;
			t.s = node.s + "FILL(1)\n";
			check();
		}
		
		if(node.y < b) {
			t.x = node.x; t.y = b; t.step = node.step+1;
			t.s = node.s + "FILL(2)\n";
			check();
		}
		
		if(node.x > 0) {
			t.x = 0; t.y = node.y; t.step = node.step+1;
			t.s = node.s + "DROP(1)\n";
			check();
			
			if(node.x <= b-node.y) {
				t.x = 0; t.y = node.y + node.x; t.step = node.step+1;
				t.s = node.s + "POUR(1,2)\n";
				check();
			}
			else {
				t.x = node.x - (b-node.y); t.y = b; t.step = node.step+1;
				t.s = node.s + "POUR(1,2)\n";
				check();
			}
		}
		
		if(node.y > 0) {
			t.y = 0; t.x = node.x; t.step = node.step+1;
			t.s = node.s + "DROP(2)\n";
			check();
			
			if(node.y <= a-node.x) {
				t.y = 0; t.x = node.y + node.x; t.step = node.step+1;
				t.s = node.s + "POUR(2,1)\n";
				check();
			}
			else {
				t.y = node.y - (a-node.x); t.x = a; t.step = node.step+1;
				t.s = node.s + "POUR(2,1)\n";
				check();
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	vis[0][0] = 1;
	
	node.x = a; node.y = 0; node.step = 1;
	node.s = "FILL(1)\n"; vis[node.x][node.y] = 1;
	q.push(node);
	
	node.x = 0; node.y = b; node.step = 1;
	node.s = "FILL(2)\n"; vis[node.x][node.y] = 1;
	q.push(node);
	
	bfs();
	if(!ans) puts("impossible");
}