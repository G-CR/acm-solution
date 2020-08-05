#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.length();
	string t1 = "XiaoQiao";
	string t2 = "XiaoHuiHui";
	bool ok1 = 0, ok2 = 0;
	
	int j = 0; int len1 = t1.length();
	for(int i = 0;i < n; i++) {
		if(t1[j] == s[i]) j++;
	}
	if(j == len1) ok1 = 1;
	
	j = 0; int len2 = t2.length();
	for(int i = 0;i < n; i++) {
		if(t2[j] == s[i]) j++;
	}
	if(j == len2) ok2 = 1;
	
	if(ok1 && ok2) puts("Happy");
	else puts("emm");
}