#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int a[N], b[N], x[N], y[N];

int n;

void read(int *a) {
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
}

int num[N];

int main() {
	scanf("%d", &n);
	read(a); read(x); read(y);
	for(int i = 1; i <= n; i++) b[i] = x[y[i]];
	
	for(int i = 1; i <= n; i++) num[b[i]]++;
	
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans += 1ll * num[a[i]];
	
	printf("%lld\n", ans);
}