#include <bits/stdc++.h>
using namespace std;

int _, p;
int vis[1000006];
vector <int> ans;

void dfs(int x, int cnt) {
	if(cnt == p+1) return;
	int fi = (2*x)%p;
	int se = (3*x)%p;
	if(!vis[fi] && fi) {
		vis[fi] = 1; 
		ans.push_back(fi);
		dfs(fi, cnt+1);
	} 
	else if(!vis[se] && se) {
		vis[se] = 1; 
		ans.push_back(se);
		dfs(se, cnt+1);
	}
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		scanf("%d", &p);
		for(int i = 1;i <= p; i++) vis[i] = 0;
		vis[1] = 1;
		ans.push_back(1);
		dfs(1, 1);
		if(ans.size() == p-1) {
			for(int i: ans) printf("%d ", i);
			puts("");
		}
		else puts("-1");
	}
}