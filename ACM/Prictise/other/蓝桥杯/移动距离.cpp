#include <bits/stdc++.h>
using namespace std;

int w, n, m;

pair <int, int> dfs(int x, int y, int now, int to, int z) {
	if(now == to) {
		return {x, y};
	}
	if(z) {
		if(y + 1 <= w) return dfs(x, y+1, now+1, to, z);
		else return dfs(x+1, y, now+1, to, !z);
	}
	else {
		if(y - 1 >= 1) return dfs(x, y-1, now+1, to, z);
		else return dfs(x+1, y, now+1, to, !z);
	}
}

int main() {
	scanf("%d %d %d", &w, &m, &n);
	auto x = dfs(1, 1, 1, m, 1);
	auto y = dfs(1, 1, 1, n, 1);
	
	printf("%d\n", abs(x.first-y.first)+abs(x.second-y.second));
}