#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, x, last = -1;
	while(~scanf("%d", &x) && x) {
		if(x == 1) {
			last = -1;
			ans++;
		}
		else if(x == 2) {
			if (last == -1) {
				ans += 2;
				last = 4;
			}
			else {
				ans += last;
				last += 2;
			}
		}
	}
	
	printf("%d\n", ans);
}