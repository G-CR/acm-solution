#include <bits/stdc++.h>
using namespace std;

string s;
map <char, char> mp;


int main() {
	cin >> s;
	reverse(s.begin(), s.end());
	mp['0'] = '0'; mp['1'] = '1';
	mp['6'] = '9'; mp['8'] = '8';
	mp['9'] = '6';
	for(int i = 0; i < s.length(); i++) {
		printf("%c", mp[s[i]]);
	}
	puts("");
}