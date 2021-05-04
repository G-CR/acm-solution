#include <bits/stdc++.h>
using namespace std;

vector <int> g;
void dfs(int a, int b) {
	if(b == 0) return;
	if(b == 1) {
//		printf("%d", a);
		g.push_back(a);
		return;
	}
	g.push_back(a/b);
//	printf("%d+1/{", a/b);
	dfs(b, a%b);
//	printf("}");
}

void dfs(int p) {
	if(p == g.size()-1) {
		printf("%d", g[p]);
		return;
	}
	if(p == g.size()-2) {
		printf("%d+1/", g[p]);
		dfs(p+1);
	}
	else {
		printf("%d+1/{", g[p]);
		dfs(p+1);
		printf("}");
	}
}

int main() {
	int _; scanf("%d", &_); while(_--) {
		g.clear();
		int a, b; scanf("%d %d", &a, &b);
		dfs(a, b);
//		for(int i : g) printf("%d ", i);
		printf("%d/%d = ", a, b);
		dfs(0);
		puts("");
	}
}