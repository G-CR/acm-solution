#include <bits/stdc++.h>
using namespace std;

int _, k, n;
map <int, bool> vis;

int main() {
	scanf("%d", &_);
	while(_--) {
		vector <int> ans;
		scanf("%d %d", &n, &k);
		vis.clear();
		
		for(int i = n;i >= 1; i--) {
			if(!vis[i] && i != k) {
				ans.push_back(i);
				vis[i] = 1;
				vis[k-i] = 1;
			}
		}
		
		printf("%lu\n", ans.size());
		for(int i : ans) printf("%d ", i);
		puts("");
	}
}