#include <bits/stdc++.h>
using namespace std;

int _;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		bool ok = 0;
		for(int i = 0;i < s.length(); i++) {
			if(ok == 0) {
				if(s[i] == 'a') printf("b");
				else printf("a");
			}
			else {
				if(s[i] == 'z') printf("y");
				else printf("z");
			}
			ok = !ok;
		}
		puts("");
	}
	
}