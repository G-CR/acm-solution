#include <bits/stdc++.h>
using namespace std;

vector <char> fuhao;
vector <int> digit;
string s;

int main() {
	cin >> s;
	int n = s.length();
	long long t = 0, ans;
	int pos = 0;
	while(pos != n && (s[pos] != '+' && s[pos] != '*')) {
		t *= 10; t += s[pos]-'0';
		pos++;
	}
	t %= 10000;
	ans = t; t = 0;
	
	for(int i = pos;i < n; i++) {
		if(s[i] == '+' || s[i] == '*') {
			fuhao.push_back(s[i]);
			if(i != pos) {
				t %= 10000;
				digit.push_back(t);
				t = 0;
			}
			
		}
		else {
			t *= 10; t += s[i]-'0';
		}
		if(i == n-1) digit.push_back(t);
	}
	
	int m = digit.size();
	for(int i = 0;i < m; i++) {
		if(fuhao[i] == '*') {
			if(i == 0) {
				digit[i] *= ans; digit[i] %= 10000;
				ans = 0;
			}
			else {
				digit[i] *= digit[i-1]; digit[i] %= 10000;
				digit[i-1] = 0;
			}
		}
	}
	for(int i = 0;i < m; i++) {
		ans += digit[i];
		ans %= 10000;
	}
	printf("%lld\n", ans);
}