#include <bits/stdc++.h>
using namespace std;

int _, n, a;
set <int> st;
vector <int> g[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		st.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) g[i].clear();
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a);
			g[a].push_back(i);
			st.insert(a);
		}
		
		int ans = 300000;
		for(int i: st) {
			int num = 0;
			for(int j = 1;j < g[i].size(); j++) {
				if(g[i][j] != g[i][j-1]+1) {
					num++;
				}
			}
			if(g[i][0] != 1) num++;
			if(g[i][g[i].size()-1] != n) num++;
			
			ans = min(ans, num);
		}
		
		printf("%d\n", ans);
	}
}