#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int ma = max(a.length(), b.length());
	while(a.length() < ma) a += '0';
	while(b.length() < ma) b += '0';
	
	string ans = "";
	for(int i = 0;i < ma; i++) {
		int t = (a[i]-'0') + (b[i]-'0');
		t %= 10;
		ans += (t+'0');
	}
	reverse(ans.begin(), ans.end());
	int pos = 0;
	while(ans[pos] == '0') pos++;
//	printf("pos = %d\n", pos);
	if(pos == ans.length()) puts("0");
	else {
		for(;pos < ans.length(); pos++) printf("%c", ans[pos]); puts("");
	}
}