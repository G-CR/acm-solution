#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s;
		string big = "", small = "";
		bool fen = 0;
		for(int i = 0;i < n; i++) {
			if(fen) {
				big += "0";
				small += s[i];
			}
			else {
				if(s[i] == '2') {
					big += "1";
					small += "1";
				}
				else if(s[i] == '0') {
					big += "0";
					small += "0";
				}
				else {
					fen = 1;
					big += "1";
					small += "0";
				}
			}
		}
		cout << big << endl << small << endl;
	}
}