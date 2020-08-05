#include <bits/stdc++.h>
using namespace std;

string s1,s2;

int main() {
	cin >> s1 >> s2;
	int n1 = s1.length();
	int n2 = s2.length();
	int i,j;
	for(i = 0;i < n2; i++) {
		for(j = 0;j < n1; j++) {
			if(s1[j] == s2[i]) {
				i++;
			}
		}
		break;
	}
	if(i == n2) puts("YES");
	else puts("NO");
}