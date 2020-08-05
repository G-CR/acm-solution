#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.length();
	int t = s[n-1]-'0';
	if(t%2==0) puts("1");
	else puts("-1");
}