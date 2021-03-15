#include <bits/stdc++.h>
using namespace std;

int _, n;
bool vis[200005];
struct node {
	long long score;
	int id;
} p[200005];
long long pre[200005];

bool cmp(node a, node b) {
	return a.score < b.score;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &p[i].score);
			p[i].id = i;
			vis[i] = 0;
		}
		sort(p+1, p+1+n, cmp);
		for(int i = 1;i <= n; i++) {
			pre[i] = pre[i-1] + p[i].score;
		}
		
		vector <int> ans;
		ans.push_back(p[n].id);
		for(int i = n-1; i >= 1; i--) {
			if(pre[i] >= p[i+1].score) {
				ans.push_back(p[i].id);
			}
			else break;
		}
		sort(ans.begin(), ans.end());
		
		printf("%lu\n", ans.size());
		for(int i: ans) printf("%d ", i);
		puts("");
	}
}