#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	scanf("%d", &n);
	bool hj = 0;
	for(int i = 1;i <= n; i++) {
		cin >> s;
		int now = s[s.length()-1]-'0';
		if(now % 2) hj = !hj;
	}
	
	if(hj) puts("1");
	else puts("0");
}