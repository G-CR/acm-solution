#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[105];
bool vis[55];
vector <int> ans;

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 1;i <= 2*n; i++) {
			scanf("%d", &a[i]);
			if(!vis[a[i]]) ans.push_back(a[i]), vis[a[i]] = 1;
		}
		for(auto i: ans) printf("%d ", i);
		puts("");
	}
}