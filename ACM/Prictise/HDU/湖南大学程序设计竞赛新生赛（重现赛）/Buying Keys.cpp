#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int ans = 0;
	while(n % 10) {
		if(n < 3) return puts("orz"), 0;
		n -= 3;
		ans++;
	}
	ans += (n/10)*3;
	printf("%d\n", ans);
}