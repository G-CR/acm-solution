#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	cin >> s >> t;
	int l = -1, r = -1;
	int ans = 0;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] != t[i]) {
			if(l == -1) l = i;
			else {
				r = i;
				ans += r-l;
				l = -1;
				r = -1;
			}
		}
	}
	
	printf("%d\n", ans);
}