#include <bits/stdc++.h>
using namespace std;

int _;
string t;
vector <char> vc;

bool check(string s) {
	int n = s.length();
	for(int i = 1;i < n; i++) {
		if(s[i] != s[i-1]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		vc.clear();
		cin >> t;
		int n = t.length();
		if(check(t)) {
			cout << t << endl;
		}
		else {
			vc.push_back(t[0]);
			for(int i = 1;i < n; i++) {
				int m = vc.size()-1;
				if(vc[m] == t[i]) {
					if(vc[m] == '1') vc.push_back('0');
					else vc.push_back('1');
				}
				vc.push_back(t[i]);
			}
			for(int i = 0;i < vc.size(); i++) printf("%c", vc[i]);
			puts("");
		}
		
	}
}