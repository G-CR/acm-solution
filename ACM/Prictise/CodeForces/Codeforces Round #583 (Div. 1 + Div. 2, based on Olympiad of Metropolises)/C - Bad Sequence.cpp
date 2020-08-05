#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool ok;
stack <char> sta;

int main() {
	scanf("%d", &n);
	cin >> s;
	for(int i = 0;i < n; i++) {
		if(!sta.empty()) {
			if(sta.top() == '(' && s[i] == ')') {
				sta.pop();
			}
			else if(s[i] == '(' && s[i+1] == ')') i++;
			else sta.push(s[i]);
		}
		else sta.push(s[i]);
	}
	
	if(sta.empty()) puts("Yes");
	else {
		char t = sta.top(); sta.pop();
		if(sta.size() == 1 && t != sta.top()) {
			puts("Yes");
		}
		else puts("No");
	}
}