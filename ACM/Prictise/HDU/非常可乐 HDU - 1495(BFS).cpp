#include <bits/stdc++.h>
using namespace std;

int s, n, m;
bool vis[105][105][105], ok;
struct Node {
	int step;
	int a, b, c;
}node, t;

queue <Node> q;

void check() {
	if(!vis[t.a][t.b][t.c]) {
		vis[t.a][t.b][t.c] = 1;
		q.push(t);
	}
}

void bfs() {
	while(!q.empty()) {
		node = q.front(); q.pop();
		
		if((node.a == node.c && node.a != 0 && node.b == 0)||(node.a==0 && node.c == node.b && node.b != 0)||(node.c==0 && node.b == node.a && node.a != 0)) {
//			printf("%d %d %d\n",node.a, node.b, node.c);
			printf("%d\n", node.step); ok = 1;
			break;
		}
		
		t.step = node.step+1;
		if(node.a) {
			// a->b
			if(node.b < n) {
				t.a = node.a-(n-node.b);
				t.b = n;
				t.c = node.c;
//				printf("a->b: %d %d %d step:%d\n",t.a,t.b,t.c,t.step);
				check();
			}
			//a->c
			if(node.c < m) {
				t.a = node.a-(m-node.c);
				t.b = node.b;
				t.c = m;
//				printf("a->c: %d %d %d step:%d\n",t.a,t.b,t.c,t.step);
				check();
			}
		}
		
		if(node.b) {
			//b->a
			t.a = node.a + node.b;
			t.b = 0;
			t.c = node.c;
//			printf("b->a: %d %d %d step:%d\n",t.a,t.b,t.c,t.step);
			check();
			
			//b->c
			t.a = node.a;
			t.b = node.b - min(node.b, m-node.c);
			t.c = node.c + min(node.b, m-node.c);
//			printf("b->c: %d %d %d step:%d\n",t.a,t.b,t.c, t.step);
			check();
		}
		
		if(node.c) {
			//c->a
			t.a = node.a + node.c;
			t.b = node.b;
			t.c = 0;
//			printf("c->a: %d %d %d step:%d\n",t.a,t.b,t.c, t.step);
			check();
			
			//c->b
			t.a = node.a;
			t.b = node.b + min(node.c, n-node.b);
			t.c = node.c - min(node.c, n-node.b);
//			printf("c->b: %d %d %d step:%d\n",t.a,t.b,t.c, t.step);
			check();
		}
	}
	if(!ok) puts("NO");
}

int main() {
	while(~scanf("%d %d %d", &s, &n, &m)) {
		memset(vis, 0, sizeof(vis)); ok = 0;
		while(!q.empty()) q.pop();
		if(s == 0) break;
		node.step = 0;
		node.a = s; node.b = 0; node.c = 0;
		q.push(node);
		bfs();
	}
}