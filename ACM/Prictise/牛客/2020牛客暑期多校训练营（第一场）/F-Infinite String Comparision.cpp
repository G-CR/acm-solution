#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
	while(cin >> s1 >> s2) {
		int n = s1.length(), m = s2.length();
		int i = 0, j = 0, cnt = 0;
		int ok = 0;
		while(1) {
			if(i == n) i -= n;
			if(j == m) j -= m;
			if(s1[i] < s2[j]) {ok = -1; break;}
			if(s1[i] > s2[j]) {ok = 1; break;}
			i++; j++;
			cnt++;
			if(cnt == 1e5) break;
		}
		if(ok == -1) puts("<");
		else if(ok == 1) puts(">");
		else puts("=");
	}
}