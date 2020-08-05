#include <bits/stdc++.h>
using namespace std;

int _, n, digit, cas;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &digit);
		printf("Case %d: ", ++cas);
		int t = digit%n, ans = 1;
		while(t) {
			t = (t*10+digit)%n;
			ans++;
		}
		printf("%d\n", ans);
	}
}