#include <bits/stdc++.h>
using namespace std;

string s;
bool ok1,ok2,ok3,ok4,ok5,ok6;
void check() {
	if(ok1 && ok2 && ok3 && ok4) {
		ok1 = 0; ok2 = 0; ok3 = 0; ok4 = 0;
	}
	if(ok5 && ok6) {
		ok5 = 0; ok6 = 0;
	}
}
int main() {
	cin >> s;
	int n = s.length();
	for(int i = 0;i < n; i++) {
		check();
		if(s[i] == '0') {
			if(!ok1) printf("1 1\n"),ok1 = 1;
			else if(!ok2) printf("1 2\n"),ok2 = 1;
			else if(!ok3) printf("1 3\n"),ok3 = 1;
			else if(!ok4) printf("1 4\n"),ok4 = 1;
		}
		else if(s[i] == '1') {
			if(!ok5) printf("3 1\n"),ok5 = 1;
			else if(!ok6) printf("3 3\n"),ok6 = 1;
		}
	}
}