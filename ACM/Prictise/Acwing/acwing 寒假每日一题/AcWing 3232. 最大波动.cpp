#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int last = -1, now, ans = 0;
	while(n--) {
		cin >> now;
		if(last == -1) last = now;
		else {
			ans = max(ans, abs(now-last));
			last = now;
		}
	}
	
	printf("%d\n", ans);
}