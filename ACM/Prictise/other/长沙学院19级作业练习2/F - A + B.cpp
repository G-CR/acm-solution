#include <bits/stdc++.h>
using namespace std;

string s[7];
int a[5];

int main() {
	ios_base::sync_with_stdio(false);
	while(cin >> s[1]) {
		int n = 1;
		int add, equ;
		while(1) {
			cin >> s[++n];
			if(s[n] == "+") add = n;
			if(s[n] == "=") {
				equ = n;
				break;
			} 
		}
		if(s[1] == "zero" && s[2] == "+" && s[3] == "zero" && s[4] == "=") break;
		memset(a,0,sizeof(a));
		int x = 0, y = 0, j = 0;
		
		for(int i = 1;i <= n; i++) {
			if(s[i] == "+") {
				x += a[j];
				if(j-1 != 0) x += a[j-1]*10;
			}
			else if(s[i] == "=") {
				y += a[j];
				if(equ-add==3) {
					y += a[j-1]*10;
				}
			}
			else {
				if(s[i] == "zero")  a[++j] = 0;
				if(s[i] == "one")   a[++j] = 1;
				if(s[i] == "two")   a[++j] = 2;
				if(s[i] == "three") a[++j] = 3;
				if(s[i] == "four")  a[++j] = 4;
				if(s[i] == "five")  a[++j] = 5;
				if(s[i] == "six")   a[++j] = 6;
				if(s[i] == "seven") a[++j] = 7;
				if(s[i] == "eight") a[++j] = 8;
				if(s[i] == "nine")  a[++j] = 9;
			}
		}
		printf("%d\n", x+y);
	}
}