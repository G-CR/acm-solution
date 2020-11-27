#include <bits/stdc++.h>
using namespace std;

int _;
string s;
char yy[] = {'a', 'e', 'i', 'o', 'u'};
bool isyy(char a) {
	for(int i = 0;i < 5; i++) if(a == yy[i]) return 1;
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		int level = 0, i = 0;
		while(i < s.length()) {
			if(isyy(s[i])) {
				int num = 1; i++;
				while(i < s.length() && isyy(s[i])) {
					num++;
					i++;
				}
				level = max(level, num);
			}
			else i++;
		}
		
		printf("%d\n", level);
	}
}