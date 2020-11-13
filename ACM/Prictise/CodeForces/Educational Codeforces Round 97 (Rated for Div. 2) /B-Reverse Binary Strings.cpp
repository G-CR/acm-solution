#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s; s += '2';
		int one = 0, zero = 0, num = 1;
		for(int i = 1;i < s.length(); i++) {
			if(s[i] == s[i-1]) {
				if(s[i-1] == '0') zero++;
				else if(s[i-1] == '1') one++;
			}
		}
		
		printf("%d\n", max(one, zero));
	}
}