#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int _, n;
ll A, B;
struct node {
	ll a, b;
} g[100005];

bool cmp(node a, node b) {
	return a.a < b.a;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %d", &A, &B, &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &g[i].a);
		}
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &g[i].b);
		}
		
		sort(g+1, g+1+n, cmp);
		
		bool ok = 1;
		for(int i = 1;i <= n; i++) {
			ll ab = ll(ceil((double)g[i].b / A));
			ll ba = ll(ceil((double)B / g[i].a));
			if(ab > ba) {
				ok = 0;
				break;
			}
			B -= ab * g[i].a;
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}