#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	vector <char> ans;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			int num = s[i]-'0'-1;
			char t = ans[ans.size()-1];
			while(num--) ans.push_back(t);
		}
		else ans.push_back(s[i]);
	}
	
	for(char i: ans) printf("%c", i);
}