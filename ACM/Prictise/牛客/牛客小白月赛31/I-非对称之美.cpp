#include <bits/stdc++.h>
using namespace std;

char s[10000006];
stack <char> sta;
int n;

int check() {
	bool ok = 1;
	if(n == 1) return ok;
	for(int i = 1;i < n; i++) {
		if(s[i] != s[i-1]) {
			ok = 0;
			break;
		}
	}
	
	return ok;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	int k = check();
	if(k == 1) {
		puts("0");
		return 0;
	}
	else if(k == 2) {
		if(s[0] == s[1]) {puts("2"); return 0;}
		else {puts("0"); return 0;}
	}
	
	int mid = n%2?(n-1)/2-1:(n-1)/2;
	for(int i = 0;i <= mid; i++) sta.push(s[i]);
	int i = n%2?mid+2:mid+1;
	bool is = 1;
	
	for(;i < n; i++) {
		char now = sta.top(); sta.pop();
		if(now != s[i]) {
			is = 0;
			break;
		}
	}
	if(is) {
		printf("%d\n", n-1);
	}
	else printf("%d\n", n);
}