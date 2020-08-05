#include <bits/stdc++.h>
using namespace std;

int _;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		int n = s.length();
		int len = 1;
		for(int i = 0;i < n; i++) {
			if(s[i] == 'L') {
				int num = 1, j;
				for(j = i;j < n; j++) {
					if(s[j] == 'R') {j--; break;} 
					num++;
				}
				len = max(len, num);
				i = j;
			}
		}
		printf("%d\n", len);
	}
}