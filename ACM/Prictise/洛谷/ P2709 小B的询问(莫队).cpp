#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long ans[50004], res;
int pos[50004], a[50004], num[50004];
struct node {
	int l, r, k;
} q[50004];

bool cmp(node a, node b) {
	if(pos[a.l] == pos[b.l]) return a.r < b.r;
	return pos[a.l] < pos[b.l];
}

void add(int n) {
	num[a[n]]++;
	res = res - (num[a[n]]-1)*(num[a[n]]-1) + (num[a[n]])*(num[a[n]]);
}

void del(int n) {
	num[a[n]]--;
	res = res - (num[a[n]]+1)*(num[a[n]]+1) + (num[a[n]])*(num[a[n]]);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int t = sqrt(n);
	for(int i = 1;i <= n; i++) pos[i] = i/t;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 0;i < m; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].k = i;
	}
	sort(q, q+m, cmp);
	
	int l = 1, r = 0;
	for(int i = 0;i < m; i++) {
		while(q[i].r > r) add(++r);
		while(q[i].l > l) del(l++);
		while(q[i].r < r) del(r--);
		while(q[i].l < l) add(--l);
		ans[q[i].k] = res;
	}
	
	for(int i = 0;i < m; i++) printf("%lld\n", ans[i]);
}