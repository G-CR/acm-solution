#include <bits/stdc++.h>
using namespace std;

int q, a, b, c;

int main() {
	cin >> q;
	while(q--) {
		cin >> a >> b >> c;
		long long ans = 1e10;
		for(int i = -1;i <= 1; i++) {
			for(int j = -1;j <= 1; j++) {
				for(int k = -1;k <= 1; k++) {
					ans = min(ans, (long long)(abs((a+i)-(b+j)) + abs((a+i)-(c+k)) + abs((b+j)-(c+k))));
				}
			}
		}
		cout << ans << endl;
	}
}