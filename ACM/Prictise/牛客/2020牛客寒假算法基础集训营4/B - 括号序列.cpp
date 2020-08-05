#include <bits/stdc++.h>
using namespace std;

string s;
stack <char> st;

int main() {
	cin >> s;
	int n = s.length();
	for(int i = 0;i < n; i++) {
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
		else if(s[i] == ')') {
			if(!st.empty() && st.top() == '(') st.pop();
			else return puts("No"), 0;
		}
		else if(s[i] == '}') {
			if(!st.empty() && st.top() == '{') st.pop();
			else return puts("No"), 0;
		}
		else if(s[i] == ']') {
			if(!st.empty() && st.top() == '[') st.pop();
			else return puts("No"), 0;
		}
	}
	if(st.empty()) puts("Yes");
	else puts("No");
}