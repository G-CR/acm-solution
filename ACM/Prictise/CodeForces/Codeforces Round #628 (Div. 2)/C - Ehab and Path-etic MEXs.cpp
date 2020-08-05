#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int ans[100005];
vector <int> vc[100005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n-1; i++) {
		scanf("%d %d", &u, &v);
		vc[u].push_back(i);
		vc[v].push_back(i);
		ans[i] = -1;
	}
	
	int num = 0;
	for(int i = 1;i <= n-1; i++) {
		if(vc[i].size() > 2) {
			for(int j = 0;j < vc[i].size(); j++) {
				if(ans[vc[i][j]] == -1) ans[vc[i][j]] = num++;
			}
		}
	}
	
	for(int i = 1;i <= n-1; i++) {
		if(ans[i] == -1) ans[i] = num++;
	}
	
	for(int i = 1;i <= n-1; i++) printf("%d\n", ans[i]);
}