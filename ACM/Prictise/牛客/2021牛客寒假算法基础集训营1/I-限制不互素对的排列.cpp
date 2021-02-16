#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> ans;
bool vis[100005];

int main() {
	scanf("%d %d", &n, &k);
	int mid = n / 2;
	if(k == mid && n < 6) return puts("-1"), 0;
	if(k < mid) {
		for(int i = 2;i <= n; i += 2) {
			ans.push_back(i);
			vis[i] = 1;
			if(ans.size() - 1 == k) break;
		}
		for(int i = 1;i <= n; i++) {
			if(!vis[i]) ans.push_back(i);
		}
	}
	else {
		for(int i = 2;i <= n; i += 2) {
			if(i == 6) continue;
			ans.push_back(i);
			vis[i] = 1;
		}
		ans.push_back(6); ans.push_back(3);
		vis[6] = 1; vis[3] = 1;
		for(int i = 1;i <= n; i++) {
			if(!vis[i]) ans.push_back(i);
		}
	}
	
	for(int i: ans) printf("%d ", i);
	puts("");
}