#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

bool check(int pos) {
	return s[pos] == '@' && s[pos+1] == 'w' && s[pos+2] == 'y' && s[pos+3] == 'k'; 
}

int main() {
	int ans = 0;
	scanf("%d", &n); while (n--) {
		char ch = getchar();
		s += ch;
		getline(cin, t);
		s += t;
		for(int i = 0; i < s.length()-3; i++) {
			if(check(i)) {
				ans++;
				break;
			}
		}
		s = "";
	}
	
	printf("%d\n", ans);
}