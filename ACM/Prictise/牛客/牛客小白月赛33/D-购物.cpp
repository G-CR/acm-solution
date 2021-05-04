#include <bits/stdc++.h>
using namespace std;

map <string, int> shop;
set <string> g[200];

int main() {
	int _; scanf("%d", &_); while(_--) {
		shop.clear();
		int m, n; scanf("%d %d", &m, &n);
		for(int i = 1; i <= m; i++) {
			string name; int num;
			cin >> name >> num;
			shop[name] = num;
		}
		
		for(int i = 1; i <= n; i++) {
			g[i].clear();
			int num; scanf("%d", &num);
			for(int j = 1; j <= num; j++) {
				string name; cin >> name;
				g[i].insert(name);
			}
			
			for(auto j: shop) {
				auto it = g[i].find(j.first);
				if(it == g[i].end()) {
					shop[j.first]--;
				}
			}
		}
		
		int ans = 0;
		for(auto i: shop) {
			if(i.second > 0) {
				ans++;
			}
		}
		if(ans == 0) puts("Need to be lucky");
		else printf("%d\n", ans);
	}
}