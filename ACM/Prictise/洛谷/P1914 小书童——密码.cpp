#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int bef[100], aft[100];

int main() {
	cin >> n >> s;
	int len = s.length();
	for(int i = 0;i < len; i++) {
		bef[i] = (s[i]-'a'+1+n)%26;
		if(bef[i] == 0) bef[i] = 26;
	}
	for(int i = 0;i < len; i++) {
		printf("%c", 'a'+bef[i]-1);
	}
}