#include <bits/stdc++.h>
using namespace std;

int _;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		int zheng1 = 0, zheng2 = 0;
		int ans = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == '(') zheng1++;
			if(s[i] == '[') zheng2++;
			if(s[i] == ')' && zheng1) {
				ans++; zheng1--;
			}
			if(s[i] == ']' && zheng2) {
				ans++; zheng2--;
			}
		}
		
		printf("%d\n", ans);
	}
}