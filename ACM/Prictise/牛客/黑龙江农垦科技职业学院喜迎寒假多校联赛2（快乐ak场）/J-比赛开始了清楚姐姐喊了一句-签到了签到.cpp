#include <bits/stdc++.h>
using namespace std;

int now = 1e9, ans;
int n, x;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(x < now) {
			now = x;
			ans = i;
		}
	}
	printf("%d\n", ans);
}