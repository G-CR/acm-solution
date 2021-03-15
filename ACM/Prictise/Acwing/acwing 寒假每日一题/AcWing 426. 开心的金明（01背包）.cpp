#include <bits/stdc++.h>
using namespace std;

int n, money;
int p[30], q[30];

int dfs(int pos, int mon) {
	if(pos > n) return 0;
	if(mon < p[pos]) return dfs(pos+1, mon);
	else {
		int t1 = dfs(pos+1, mon-p[pos]) + p[pos]*q[pos];
		int t2 = dfs(pos+1, mon);
		return max(t1, t2);
	}
}

int main() {
	scanf("%d %d", &money, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &p[i], &q[i]);
	}
	
	printf("%d\n", dfs(1, money));
}