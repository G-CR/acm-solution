#include <iostream>
#include <cstdio>
using namespace std;

int n, m, k, u, v;
int father[30004];

int find(int x) {
	if(x == father[x]) return x;
	return find(father[x]);
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0) break;
		for(int i = 0;i <= n; i++) father[i] = i;
		while(m--) {
			scanf("%d", &k);
			scanf("%d", &u);
			for(int i = 1;i < k; i++) {
				scanf("%d", &v);
				father[find(v)] = find(u);
				u = v;
			}
		}
		
		int ans = 0;
		for(int i = 0;i <= n; i++) {
			if(find(i) == find(0)) ans++;
		}
		
		printf("%d\n", ans);
	}
}