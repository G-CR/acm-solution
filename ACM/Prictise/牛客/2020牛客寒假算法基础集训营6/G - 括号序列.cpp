#include <bits/stdc++.h>
using namespace std;

int T, n;
char c;
stack<char> sta;

int main() {
	scanf("%d", &T);
	while(T--) {
		while(!sta.empty()) sta.pop();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf(" %c", &c);
			if(sta.empty()) sta.push(c);
			else {
				if(c == '(') sta.push(c);
				if(c == ')') {
					if(sta.top() == '(') sta.pop();
					else sta.push(c);
				}
			}
		}
		printf("%d\n", (int)sta.size());
	}
}