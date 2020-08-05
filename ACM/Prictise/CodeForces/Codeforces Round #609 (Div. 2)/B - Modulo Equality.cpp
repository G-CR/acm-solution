#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
int n, m;
int a[2004], b[2004], c[2004];

bool check() {
	sort(c+1,c+1+n);
	for(int i = 1;i <= n; i++) {
		if(c[i] != b[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);sort(a+1, a+1+n);
	for(int i = 1;i <= n; i++) scanf("%d", &b[i]);sort(b+1, b+1+n);
	int ans = inf, t;
	for(int i = 1;i <= n; i++) {
		t = b[1]-a[i]>=0?b[1]-a[i]:b[1]-a[i]+m;
		for(int i = 1;i <= n; i++) c[i] = a[i];
		for(int j = 1;j <= n; j++) {
			c[j] = (c[j]+t)%m;
		}
		if(check()) ans = min(ans, t);
	}
	printf("%d\n", ans);
}