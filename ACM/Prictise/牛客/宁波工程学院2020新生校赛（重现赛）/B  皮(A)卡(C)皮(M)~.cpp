#include <bits/stdc++.h>
using namespace std;

string s;
int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		bool ok1 = 0, ok2 = 0, ok3 = 0;
		cin >> s;
		int n = s.length();
		for(int i = 0;i < n; i++) {
			if(s[i] == 'A') ok1 = 1;
			if(s[i] == 'C') ok2 = 1;
			if(s[i] == 'M') ok3 = 1;
		}
		
		if(!ok1 || !ok2 || !ok3) {
			if(!ok1) puts("A");
			if(!ok2) puts("C");
			if(!ok3)puts("M");
		}
		else puts("-1");
	}
	
}