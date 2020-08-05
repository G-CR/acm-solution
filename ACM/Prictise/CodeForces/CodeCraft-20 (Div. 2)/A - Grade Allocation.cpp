#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1005];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		int sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		printf("%d\n", min(sum, m));
	}
}