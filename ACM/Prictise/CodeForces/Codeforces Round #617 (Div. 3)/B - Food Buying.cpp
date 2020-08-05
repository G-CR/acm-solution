#include <bits/stdc++.h>
using namespace std;

int t, s;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &s);
		int ans = 0;
		while(s) {
//			printf("s = %d\n", s);
			if(s >= 10) {
				int t = s/10*10;
				s -= t; ans += t;
				s += t/10;
			}
			else {
				ans += s;
				s = 0;
			}
		}
		printf("%d\n", ans);
	}
}