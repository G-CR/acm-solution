#include <bits/stdc++.h>
using namespace std;

int _;
string s;

int check(string s) {
	bool dig = 0;
	int pos = 0;
	while(pos < s.length()) {
		if(s[pos] >= 'A' && s[pos] <= 'Z' && dig) return 1;
		if(s[pos] >= '0' && s[pos] <= '9') {
			dig = 1;
		}
		pos++;
	}
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		if(check(s)) {
			int r = 0, c = 0, i;
			for(i = 1;s[i] >= '0' && s[i] <= '9'; i++) {
				r = r * 10 + (s[i]-'0');
			}
			i++;
			for(;i < s.length(); i++) {
				c = c * 10 + (s[i]-'0');
			}
			
			string res = "";
			char t;
			while(c) {
				if(c%26==0){
					res = 'Z' + res;
					c /= 26;
					c--;
				}
				else {
					res = (char)('A'-1+c%26) + res;
					c /= 26;
				}
			}
			cout << res << r << endl;
		}
		
		else {
			int i, res = 0;
			string fi = "", r = "";
			for(i = 0;s[i] >= 'A' && s[i] <= 'Z'; i++) {
				fi += s[i];
			}
			for(;i < s.length(); i++) {
				r += s[i];
			}
			for(char now: fi) {
				res = res * 26 + (now-'A'+1);
			}
			cout << "R" << r << "C" << res << endl;
		}
	}
}