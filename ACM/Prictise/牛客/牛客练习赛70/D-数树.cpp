#include <bits/stdc++.h>
using namespace std;

int _, ans, cas, u, v, cnt;
map <int, int> mp;
set <int> tree[100005];

int lisan(int x) {
	if(!mp[x]) mp[x] = ++cnt;
	return mp[x];
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &cas);
		if(cas != 3) {
			scanf("%d %d", &u, &v);
			u = lisan(u); v = lisan(v);
			if(cas == 1) {
				if(tree[u].find(v) != tree[u].end()) continue;
				if(tree[u].size() == 0 && tree[v].size() == 0) ans++;
				else if(tree[u].size() && tree[v].size()) ans--;
				tree[u].insert(v);
				tree[v].insert(u);
			}
			else if(cas == 2) {
				if(tree[u].find(v) == tree[u].end()) continue;
				if(tree[u].size() == 1 && tree[v].size() == 1) ans--;
				else if(tree[u].size() > 1 && tree[v].size() > 1) ans++;
				tree[u].erase(v);
				tree[v].erase(u);
			}
		}
		else {
			printf("%d\n", ans);
		}
	}
}