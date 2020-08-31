#include <bits/stdc++.h>
using namespace std;

int _, n;
int num[30];
string s;

bool check() {
	for(int i = 0;i < 26; i++) {
		if(num[i]%n != 0) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(num, 0, sizeof num);
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			cin >> s;
			for(char i: s) num[i-'a']++;
		}
		
		if(check()) puts("YES");
		else puts("NO");
	}
}