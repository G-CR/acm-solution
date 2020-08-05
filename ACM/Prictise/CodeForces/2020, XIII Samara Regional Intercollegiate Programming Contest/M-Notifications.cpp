#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int t, d;
}tv[200005];
queue <int> q;

bool cmp(node a, node b) {
	if(a.t == b.t) return a.d < b.d;
	return a.t < b.t;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &tv[i].t, &tv[i].d);
	}
	sort(tv+1, tv+1+n, cmp);
	
	long long ans = tv[1].t;
	for(int i = 1;i <= n; i++) {
		if(ans < tv[i].t) ans = tv[i].t;
		ans += tv[i].d;
	}
	
	printf("%lld\n", ans);
}