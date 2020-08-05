#include <bits/stdc++.h>
using namespace std;

int n, m, d, c;
queue<int> q;

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 1;i <= m; i++) {
		for(int j = 1;j < d; j++) q.push(0);
		scanf("%d", &c);
		for(int j = 1;j <= c; j++) q.push(i);
	}
	for(int i = 1;i < d; i++) q.push(0);
	
	if(q.size() < n) puts("NO");
	else {
		puts("YES");
		int t = q.size() - n;
		while(!q.empty()) {
			int res = q.front(); q.pop();
			if(t != 0 && res == 0) {
				t--; continue;
			}
			printf("%d ", res);
		}
	}
	puts("");
}