#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1000006];
struct node {
	long long d;
	int v;
} b[1000006];

bool cmp1(long long a, long long b) {
	return a > b;
}

bool cmp2(node a, node b) {
	if(a.v == b.v) return a.d < b.d;
	return a.v > b.v;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+1+n, cmp1);
	
	for(int i = 1;i <= m; i++) {
		scanf("%lld", &b[i].d);
	}
	for(int i = 1;i <= m; i++) {
		scanf("%d", &b[i].v);
	}
	sort(b+1, b+1+m, cmp2);
	
	int now = 1;
	long long ans = 0;
	for(int i = 1;i <= m; i++) {
		if(a[now] > b[i].d) {
			for(int j = now;j <= n; j++) {
				if(a[j] <= b[i].d || b[i].v < 0) {
					now = j;
					break;
				}
				ans += b[i].v;
			}
		}
		if(b[i].v < 0) break;
	}
	
	printf("%lld\n", ans);
}


/////// 法二
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long x;
set <long long> a;
map <long long, int> num;

struct node {
	long long d;
	int v;
} jidi[1000006];

bool cmp(node a, node b) {
	if(a.v == b.v) return a.d < b.d;
	return a.v > b.v;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &x);
		num[x]++;
		a.insert(x);
	}
	
	for(int i = 1;i <= m; i++) {
		scanf("%lld", &jidi[i].d);
	}
	for(int i = 1;i <= m; i++) {
		scanf("%d", &jidi[i].v);
	}
	sort(jidi+1, jidi+1+m, cmp);
	
	long long ans = 0;
	set <long long>::iterator it;
	for(int i = 1;i <= m; i++) {
		if(jidi[i].v < 0) break;
		while(1) {
			it = a.upper_bound(jidi[i].d);
			if(it != a.end()) {
				ans += jidi[i].v * num[*it];
				a.erase(it);
			}
			else break;
		}
		
	}
	
	printf("%lld\n", ans);
}