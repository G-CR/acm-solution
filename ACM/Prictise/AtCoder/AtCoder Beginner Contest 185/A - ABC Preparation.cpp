#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 200;
	for(int i = 1; i <= 4; i++) {
		int a; scanf("%d", &a);
		ans = min(ans, a);
	}
	printf("%d\n", ans);
}