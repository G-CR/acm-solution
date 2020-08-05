#include <bits/stdc++.h>
using namespace std;

int _;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		int dignum = 0, starnum = 0, ans = 0, now = 0;
		cin >> s;
		int n = s.length();
		int tail = n-1;
		for(int i = 0;i < n; i++) {
			if(s[i] == '*') starnum++;
			else dignum++;
		}
		if(dignum < starnum+1) {
			ans += (starnum+1-dignum);
			now = ans;
		}
		
		for(int i = 0;i < n; i++) {
			if(s[i] == '*') {
				if(now < 2) {
					while(s[tail] == '*' && tail >= 0) tail--;
					swap(s[i], s[tail]);
					now++;
					ans++;
				}
				else now--;
			}
			else {
				now++;
			}
		}
		printf("%d\n", ans);
	}
}