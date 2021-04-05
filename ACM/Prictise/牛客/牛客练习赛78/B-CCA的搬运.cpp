#include <bits/stdc++.h>
using namespace std;

int n, m, id;
bool vis[2002];
long long w[2003];
stack <int> sta, t;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	
	long long pre = 0, ans = 0;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &id);
		if(vis[id]) {
			long long now = 0;
			while(!sta.empty()) {
				if(sta.top() == id) {
					sta.pop();
					break;
				}
				else {
					ans += w[sta.top()];
					t.push(sta.top());
					sta.pop();
				}
			}
			while(!t.empty()) {
				sta.push(t.top());
				t.pop();
			}
			sta.push(id);
		}
		else {
			vis[id] = 1;
			ans += pre;
			sta.push(id);
			pre += w[id];
		}
	}
	
	printf("%lld\n", ans);
}