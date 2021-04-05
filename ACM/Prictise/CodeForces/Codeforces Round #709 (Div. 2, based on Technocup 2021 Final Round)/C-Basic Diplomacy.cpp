#include <bits/stdc++.h>
using namespace std;

int _, n, m, ans[100005], num[100005];
struct node {
	vector <int> p;
	int id;
} g[100005];

bool cmp(node a, node b) {
	return a.p.size() < b.p.size();
}

void out() {
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < g[i].p.size(); j++) {
			printf("%d ", g[i].p[j]);
		}
		puts("");
	}
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) num[i] = 0;
		for(int i = 1; i <= m; i++) g[i].p.clear();
		
		for(int i = 1; i <= m; i++) {
			int cnt, p; scanf("%d", &cnt);
			g[i].id = i;
			for(int j = 1; j <= cnt; j++) {
				scanf("%d", &p);
				g[i].p.push_back(p);
			}
		}
		
		sort(g+1, g+1+m, cmp);
		
		bool ok = 0;
		for(int i = 1; i <= m; i++) {
			ok = 0;
			for(int j = 0; j < g[i].p.size(); j++) {
				int now = g[i].p[j];
				if(num[now] < (m + 1) / 2) {
					ok = 1;
					ans[g[i].id] = now;
					num[now]++;
					break;
				}
			}
			if(!ok) {
				puts("NO");
				break;
			}
		}
		if(ok) {
			puts("YES");
			for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
			puts("");
		}
	}
}