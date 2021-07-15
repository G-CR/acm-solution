#include <bits/stdc++.h>
using namespace std;

int n;
int a[103], b[103];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	int l = a[1], r = b[1];
	for(int i = 2; i <= n; i++) {
		l = max(l, a[i]);
		r = min(r, b[i]);
	}
	if(l > r) puts("0");
	else printf("%d\n", r-l+1);
}