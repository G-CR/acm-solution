#include <bits/stdc++.h>
using namespace std;

string s;
stack <char> sst;
int main() {
	cin >> s;
	int n = s.length(),sum = 0;
	for(int i = 0;i < n; i++) {
		if(!sst.empty()) {
			if(sst.top() == s[i]) {
				sst.pop();
				sum++;
				continue;
			}
		}
		sst.push(s[i]);
	}
	if(sum % 2 == 1) puts("YES");
	else puts("NO");
}