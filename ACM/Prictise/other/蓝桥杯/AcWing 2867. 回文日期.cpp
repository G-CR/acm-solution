#include <bits/stdc++.h>
using namespace std;

int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isrun(int y) {
	return (y % 4 == 0 && y % 100) || y % 400 == 0;
}

string cg(int y, int m, int d) {
	string s = "";
	s += d % 10 + '0'; d /= 10;
	if(!d) s += '0';
	else s += d + '0';
	
	s += m % 10 + '0'; m /= 10;
	if(!m) s += '0';
	else s += m + '0';
	
	while(y) {
		s += y % 10 + '0';
		y /= 10;
	}
	reverse(s.begin(), s.end());
	
	return s;
}

bool nice(string k) {
	for(int i = 0, j = k.length()-1; i < j; i++, j--) {
		if(k[i] != k[j]) return 0;
	}
	return 1;
}

bool wow(string s) {
	return s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[0] == s[2] && s[2] == s[5] && s[5] == s[7] && s[1] != s[7];
}

int main() {
	int y, m, d;
	scanf("%4d %2d %2d", &y, &m, &d);
	string ans1 = "", ans2 = "";
	while(1) {
		d++; int num = mon[m]; if(m == 2 && isrun(y)) num++;
		if(d > num) {d = 1; m++;}
		if(m > 12) {m = 1; y++;}
		string now = cg(y, m, d);
		
		if(nice(now)) {
			if(ans1.empty()){
				ans1 = now;
			}
			if(wow(now)) {
				ans2 = now;
			}
		}
		if(ans1.length() && ans2.length()) break;
	}
	cout << ans1 << "\n" << ans2 << "\n";
}