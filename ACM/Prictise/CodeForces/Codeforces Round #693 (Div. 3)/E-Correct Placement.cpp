#include <bits/stdc++.h>
using namespace std;

int _, n;
int res[200005], pos[200005], ans[200005];
struct node {
	int id;
	long long h, w;
} p[200005];

bool cmp(node a, node b) {
	if(a.h == b.h) return a.w < b.w;
	return a.h > b.h;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			p[i].id = i;
			scanf("%lld %lld", &p[i].h, &p[i].w);
			if(p[i].h < p[i].w) swap(p[i].h, p[i].w);
		}
		sort(p+1, p+1+n, cmp);
		
		res[n+1] = 1e9; pos[n+1] = -1;
		for(int i = n;i >= 1; i--) {
			if(p[i].w <= res[i+1]) {
				res[i] = p[i].w;
				pos[i] = p[i].id;
			}
			else {
				res[i] = res[i+1];
				pos[i] = pos[i+1];
			}
		}
		
		for(int i = 1;i <= n; i++) {
			if(p[i].w <= res[i+1]) {
				ans[p[i].id] = -1;
			}
			else {
				ans[p[i].id] = pos[i+1];
			}
		}
		
		for(int i = 1;i <= n; i++) {
			printf("%d ", ans[i]);
		} puts("");
	}
}