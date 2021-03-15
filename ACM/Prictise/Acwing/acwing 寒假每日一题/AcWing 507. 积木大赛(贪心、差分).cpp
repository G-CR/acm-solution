#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int ans = 0, la = 0;
	while(n--) {
		int x;
		scanf("%d", &x);
		if(x > la) ans += x - la;
		la = x;
	}
	printf("%d\n", ans);
}