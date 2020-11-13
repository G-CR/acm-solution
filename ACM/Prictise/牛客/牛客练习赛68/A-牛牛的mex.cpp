#include <bits/stdc++.h>
using namespace std;

int n, q, l, r;
int a[100005];
int pre[100005], beh[100005];

int main() {
	scanf("%d %d", &n, &q);
	pre[0] = beh[n+1] = n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = min(pre[i-1], a[i]);
	}
	
	for(int i = n; i >= 1; i--) {
		beh[i] = min(beh[i+1], a[i]);
	}

	while(q--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", min(pre[l-1], beh[r+1]));
	}
}