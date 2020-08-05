#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;
stack <char> sta;

int main() {
	scanf("%d", &_);
	while(_--) {
		while(!sta.empty()) sta.pop();
		scanf("%d", &n);
		cin >> s;
		for(int i = 0;i < n; i++) {
			if(!sta.empty()) {
				if(sta.top() == '('&&s[i]==')') sta.pop();
				else sta.push(s[i]);
			}
			else sta.push(s[i]);
		}
		
		printf("%d\n", (int)sta.size()/2);
	}
}