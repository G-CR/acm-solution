#include <bits/stdc++.h>
using namespace std;

string s;

pair <bool, int> check() {
	long long res = 0;
	char t = s[s.length()-1];
	int fin;
	if(t == 'X') fin = 10;
	else fin = t - '0';
	int num = 0;
	for(int i = 0;i < s.length()-1; i++) {
		if(s[i] == '-') continue;
		res += (++num) * (s[i]-'0');
	}
	
	if(res % 11 == fin) return {1, 1};
	else return {0, res%11};
}

int main() {
	cin >> s;
	auto t = check();
	if(t.first) puts("Right");
	else {
		for(int i = 0;i < s.length()-1; i++) printf("%c", s[i]);
		printf("%c\n", t.second==10?'X':t.second+'0');
	}
}