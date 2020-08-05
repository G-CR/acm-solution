#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	scanf("%d", &t);
	while(t--) {
		int sum = 0;
		cin >> s;
		int n = s.length();
		for(int i = 0;i < n; i++) {
			if(s[i] == 'H') sum += 1;
			if(s[i] == 'C') sum += 12;
			if(s[i] == 'O') sum += 16;
		}
		printf("%d\n", sum);
	}
}