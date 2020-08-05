#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
double n, a, b;

int main() {
	cin >> n;
	int ans = inf;
	for(int i = 1;i <= 3; i++) {
		cin >> a >> b;
		int t = ceil(n/a);
		ans = min(ans, (int)(t*b));
	}
	
	cout << ans << endl;
}