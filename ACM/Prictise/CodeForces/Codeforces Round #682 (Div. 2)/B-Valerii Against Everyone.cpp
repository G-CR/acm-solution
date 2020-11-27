#include <bits/stdc++.h>
using namespace std;

int _, n;
long long b[1003];
map <long long, bool> vis;

int main() {
	scanf("%d", &_);
	while(_--) {
		vis.clear();
		scanf("%d", &n);
		bool ok = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &b[i]);
			if(vis[b[i]]) ok = 1;
			vis[b[i]] = 1;
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}