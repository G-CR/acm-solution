#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int ans = 0;
	for(int i = 0;i < s.length()-2; i++) {
		if(s[i] == 'o' && s[i+1] == 'r' && s[i+2] == 'a') {
			ans++;
		}
	}
	if(ans) printf("%d\n", ans);
	else puts("yare yare daze");
}