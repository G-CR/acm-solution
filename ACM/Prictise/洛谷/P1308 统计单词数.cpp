#include <bits/stdc++.h>
using namespace std;

string t, s;
int ans, fir = -1;

int main() {
	getline(cin, t);
	getline(cin, s);
	int n1 = t.length();
	int n2 = s.length();
	for(int i = 0;i < n2; i++) {
		if((s[i] == t[0] || abs(t[0]-s[i]) == 32) && s[i+n1] == ' ' && (s[i-1] == ' ' || i == 0)) {
			bool ok = 1;
			for(int j = 0;j < n1; j++) {
				if(t[j] == s[i+j] || abs(t[j]-s[i+j]) == 32) continue;
				else {
					ok = 0;
					break;
				}
			}
			
			if(ok) {
				if(fir == -1) fir = i;
				ans++;
			}
		}
	}
	if(ans) printf("%d %d\n", ans, fir);
	else puts("-1");
}