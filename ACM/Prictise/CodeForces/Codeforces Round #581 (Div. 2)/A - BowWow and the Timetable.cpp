#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;
int main() {
	cin >> s;
	bool ok = 0;
	int n = s.length();
	for(int i = 0;i < n; i++) {
		if(s[i] != '0' && i > 0) {
			ok = 1; break;
		}
	}
	ans = (n-1)/2;
	if(ok) ans++;
	if(!ok && !(n%2)) ans++;
	printf("%d\n", ans);
}