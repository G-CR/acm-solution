#include <bits/stdc++.h>
using namespace std;

int _, t, n, c0, c1, h;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d %d", &n, &c0, &c1, &h);
		cin >> s;
		int ans = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == '0') {
				ans += min(c0, c1+h);
			}
			else if(s[i] == '1') {
				ans += min(c1, c0+h);
			}
		}
		
		printf("%d\n", ans);
	}
}