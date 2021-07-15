#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int ans = n, now = n;
	while(now >= 3) {
		int ping = now / 3;
		ans += ping;
		now -= ping * 2;
	}
	
	printf("%d\n", ans);
}