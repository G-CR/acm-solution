//https://ac.nowcoder.com/acm/problem/50439
#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	long long v;
	int s;
	bool operator < (const node&o) const {
		return o.v < v;
	}
}soldier[100005];
bool cmp(node a, node b) {
	return a.s > b.s;
}
priority_queue <node> q;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld %d", &soldier[i].v, &soldier[i].s);
	sort(soldier+1, soldier+1+n, cmp);
	long long now = 0, ans = 0;
	for(int i = 1;i <= n; i++) {
		while(q.size() >= soldier[i].s) {
			now -= q.top().v;
			q.pop();
		}
		now += soldier[i].v;
		q.push(soldier[i]);
		ans = max(ans, now);
	}
	printf("%lld\n", ans);
}