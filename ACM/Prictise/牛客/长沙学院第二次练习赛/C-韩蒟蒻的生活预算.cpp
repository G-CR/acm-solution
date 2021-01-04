#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	while(~scanf("%d", &n)) {
		int ans = 0;
		for(int i = 1;i <= n; i++) {
			cin >> s;
			int now = s[s.length()-1]-'0';
			if(now == 0) continue;
			else if(now >= 5) {
				ans += 10-now;
			}
			else {
				ans -= now;
			}
		}
		double res = ans;
		res /= 1000.0;
		printf("%.3lf\n", res);
	}
}