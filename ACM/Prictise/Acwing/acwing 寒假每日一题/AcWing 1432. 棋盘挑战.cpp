#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> ans;
bool vis1[15], vis2[30], vis3[30];

void dfs(int row) {
	if(row == n+1) {
		++k;
		if(k <= 3) {
			for(int i: ans) printf("%d ", i);
			puts("");
		}
		return;
	}
	
	for(int i = 1;i <= n; i++) {
		if(!vis1[i] && !vis2[row+i] && !vis3[row-i+n]) {
			ans.push_back(i);
			vis1[i] = vis2[row+i] = vis3[row-i+n] = 1;
			dfs(row+1);
			ans.pop_back();
			vis1[i] = vis2[row+i] = vis3[row-i+n] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", k);
}