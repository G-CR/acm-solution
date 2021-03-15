#include <bits/stdc++.h>
using namespace std;

int _, n;
long long k, a[100005];
map <int, bool> vis;
priority_queue<int> q;

int main() {
	scanf("%d", &_);
	while(_--) {
		bool ok = 1;
		vis.clear();
		while(!q.empty()) q.pop();
		
		scanf("%d %lld", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			if(a[i] >= n) ok = 0;
			vis[a[i]] = 1;
			q.push(a[i]);
		}
		
		if(ok || !k) printf("%lld\n", n + k);
		else {
			for(int i = 0; i < n; i++) {
				if(!vis[i]) {
					int now = ceil((1.0 * i + q.top()) / 2);
					if(!vis[now]) {
						printf("%d\n", n+1);
					}
					else printf("%d\n", n);
					
					break;
				}
			}
		}
	}
}