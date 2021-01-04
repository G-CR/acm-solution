#include <bits/stdc++.h>
using namespace std;

int _, n1, n2;
string s1, s2;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n1, &n2);
		cin >> s1 >> s2;
		string t1 = "", t2 = "";
		for(char i: s1) {
			if(i == '0') {
				t1 += '1'; t1 += '1';
			}
			else t1 += '1';
		}
		
		for(char i: s2) {
			if(i == '0') {
				t2 += '1'; t2 += '1';
			}
			else t2 += '1';
		}
		
		
		int len1 = ((int)t1.length())%3;
		int len2 = ((int)t2.length())%3;
		
		if(len1 != len2) puts("NO");
		else puts("YES");
	}
}