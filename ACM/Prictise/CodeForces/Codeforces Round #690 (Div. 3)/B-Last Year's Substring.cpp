#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s;
		bool ok = 0;
		if(s[n-4] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ok = 1;
		if(s[0] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ok = 1;
		if(s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0')ok = 1;
		
		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0') ok = 1;
		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') ok = 1;
		
		if(ok) puts("YES");
		else puts("NO");
	}
}