#include <bits/stdc++.h>
using namespace std;

int n;
string t;

int cal(string a) {
	int res = 0;
	for(int i = 0;i < a.length(); i++) {
		if(a[i] == '%') res++;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	int ans = 0;
	while(getline(cin, t)) {
		
		string s = "";
		for(int i = 0;i < t.length(); i++) {
			if(t[i] != ' ') s += t[i];
		}
		if(s.length() < 5) continue;
		bool ok = 0;
		for(int i = 0;i < s.length()-3; i++) {
			if(s[i] == 'A' && s[i+1] == 'l' && s[i+2] == 'a' && s[i+3] == 'n') {
				ok = 1;
				break;
			}
		}
		
		if(ok) ans += cal(s);
	}
	
	printf("%d\n", ans);
}