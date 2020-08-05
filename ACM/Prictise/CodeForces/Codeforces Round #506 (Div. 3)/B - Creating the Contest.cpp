#include <bits/stdc++.h>
using namespace std;

int n, t, x;

int main() {
	int ans = 1, num = 1;
	scanf("%d", &n);
	scanf("%d", &t);
	for(int i = 2;i <= n; i++) {
		scanf("%d", &x);
		if(t*2 >= x) {
			num++;
		}
		else {
			num = 1;
		}
		t = x;
		ans = max(ans, num);
	}
	printf("%d\n", ans);
}