#include <bits/stdc++.h>
using namespace std;

int _;
char s[100007];
deque <int> q;
stack <int> sta;

int main() {
	scanf("%d", &_);
	while(_--) {
		while(!q.empty()) q.pop_back();
		while(!sta.empty()) sta.pop();
		scanf("%s", s);
		bool ok = 1;
		int len = strlen(s);
		for(int i = 0;i < len; i++) {
			if(s[i] == '(') sta.push(i);
			else if(s[i] == ')') {
				if(!sta.empty()) {
					sta.pop();
				}
				else if(!q.empty()) {
					s[q.front()] = '(';
					q.pop_front();
				}
				else {
					ok = 0;
					break;
				}
			}
			else {
				q.push_back(i);
			}
		}
		
		while(!sta.empty()) {
			if(!q.empty() && q.back() > sta.top()) {
				s[q.back()] = ')';
				sta.pop();
				q.pop_back();
			}
			else {
				ok = 0;
				break;
			}
		}
		
		if(ok) {
			for(int i = 0;i < len; i++) {
				if(s[i] != '*') printf("%c", s[i]);
			}
			puts("");
		}
		else puts("No solution!");
	}
}