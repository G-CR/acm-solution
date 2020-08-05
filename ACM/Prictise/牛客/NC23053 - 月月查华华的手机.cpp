#include <bits/stdc++.h>
using namespace std;

char s[1000006];
int Next[1000006][26];
int _;

int main() {
	scanf("%s", (s+1));
	int n = strlen(s+1);
	for(int i = n-1;i >= 0; i--) {
		for(int j = 0;j < 26; j++) {
			Next[i][j] = Next[i+1][j];
		}
		Next[i][s[i+1]-'a'] = i+1;
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		bool ok = 1;
		int pos = 0;
		for(int i = 1;i <= n; i++) {
			if(Next[pos][s[i]-'a']) pos = Next[pos][s[i]-'a'];
			else {
				ok = 0;
				break;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
}