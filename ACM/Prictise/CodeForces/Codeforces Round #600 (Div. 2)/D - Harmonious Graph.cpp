#include <bits/stdc++.h>
using namespace std;

int n, m;
int father[200005];
bool ok[200005];

int find(int x) {
	if(x == father[x]) return x;
	else return father[x] = find(father[x]);
}

void unionSet(int a, int b) {
	int u = find(father[a]);
	int v = find(father[b]);
	father[u] = father[v] = max(u, v);
}

int main() {
	scanf("%d %d", &n, &m);
	int a, b, sta = n, end = 0;
	for(int i = 1;i <= n; i++) father[i] = i;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &a, &b);
		unionSet(a, b);
		ok[a] = ok[b] = 1;
		sta = min(sta, min(a,b));
		end = max(end, max(a,b));
	}
	int ans = 0;
	while(sta <= end) {
		int w = find(sta);
		for(int i = sta;i <= w; i++) {
//			printf("i = %d find(i) = %d w = %d\n", i, find(i), w);
			if(find(i) != w) {
				ans++;
				unionSet(i, w);
				w = max(w, find(i));
			}
		}
		for(sta = w+1;sta <= end && father[sta] == sta; sta++);
	}
	printf("%d\n", ans);
}