#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
	ll w, s;
} cow[50004];
ll pre[50004];
int n;

bool cmp(node a, node b) {
	return (a.w+a.s < b.w+b.s);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld %lld", &cow[i].w, &cow[i].s);
	sort(cow+1, cow+1+n, cmp);
	for(int i = 1;i <= n; i++) pre[i] = pre[i-1] + cow[i].w;
	ll ans = -1e18;
	for(int i = 1;i <= n; i++) ans = max(ans, pre[i-1]-cow[i].s);
	printf("%lld\n", ans);
}