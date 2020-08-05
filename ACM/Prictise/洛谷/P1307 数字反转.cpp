#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	string t = "";
	if(s[0] == '-') t += s[0];
	int n = s.length(); n--;
	while(s[n] == '0') n--;
	
	for(int i = n;i >= (t[0]=='-'?1:0); i--) t += s[i];
	cout << t << endl;
}