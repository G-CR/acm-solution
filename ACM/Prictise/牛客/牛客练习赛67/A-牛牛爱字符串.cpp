#include <bits/stdc++.h>
using namespace std;

string s;
vector <string> res;

int main() {
	while(getline(cin, s)) {
		s += 'a';
		res.clear();
		string now = "";
		bool ok = 0;
		for(int i = 0;i < s.length(); i++) {
			if(isdigit(s[i])) {
				ok = 1;
				if(s[i] == '0' && now == "") continue;
				now += s[i];
			}
			else {
				if(ok) {
					if(now == "") now += '0';
					ok = 0;
					res.push_back(now);
					now = "";
				}
			}
		}
		
		for(int i = 0;i < res.size(); i++) {
			cout << res[i];
			if(i < res.size()-1) printf("%c", ' ');
		}
		puts("");
	}
}


// python

import re
while True:
	try:
		s = input()
	except:
		break
	for _ in re.findall(r'\d+', s):
		print(int(_), end=' ')
	print()