#include <bits/stdc++.h>
using namespace std;

int num[30];
string s;

int main() {
	int maxn = 0;
	for(int i = 1;i <= 4; i++) {
		getline(cin, s);
		int n = s.length();
		for(int i = 0;i < n; i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') 
				num[s[i]-'A']++;
		}
	}
	
	for(int i = 0;i < 26; i++) maxn = max(maxn, num[i]);
	for(int i = maxn;i >= 1; i--) {
		for(int j = 0;j < 26; j++) {
			if(num[j] >= i) printf("*");
			else printf(" ");
			printf(" ");
		}
		puts("");
	}
	for(int i = 0;i < 26; i++) printf("%c ", 'A'+i);
}