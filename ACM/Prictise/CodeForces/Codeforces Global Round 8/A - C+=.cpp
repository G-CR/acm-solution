#include <bits/stdc++.h>
using namespace std;

int _, a, b, c;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &a, &b, &c);
		if(a > b) swap(a, b);
		int cnt = 1, ans = a+b;
		while(ans <= c) {
			int t = ans;
			ans += b;
			b = t;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}