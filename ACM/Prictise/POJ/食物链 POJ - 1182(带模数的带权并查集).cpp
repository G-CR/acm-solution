#include <iostream>
using namespace std;

int fa[50004], sum[50004];

int find(int x) {
	if(fa[x] != x) {
		int t = fa[x];
		fa[x] = find(fa[x]);
		sum[x] = (sum[x]+sum[t])%3;
	}
	return fa[x];
}

int main() {
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) fa[i] = i;
	while(k--) {
		int x, y, d;
		scanf("%d %d %d", &d, &x, &y);
		if(x > n || y > n || (d == 2 && x == y)) {ans++; continue;}
		int fx = find(x);
		int fy = find(y);
		if(fx == fy) {
			if(d-1 != (sum[x]-sum[y]+3)%3) ans++;
		}
		else {
			fa[fx] = fy;
			sum[fx] = (-sum[x]+sum[y]+d-1+3)%3;
		}
	}
	printf("%d\n", ans);
}