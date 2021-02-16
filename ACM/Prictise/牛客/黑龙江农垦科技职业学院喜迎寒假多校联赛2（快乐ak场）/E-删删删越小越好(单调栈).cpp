#include <bits/stdc++.h>
using namespace std;

string s;
int k;
stack <char> res;

int main() {
	cin >> s;
	scanf("%d", &k);
	int pos = 0;
	
	while(pos < s.length()) {
		if(!k) {
			res.push(s[pos++]);
			continue;
		}
		if(res.empty()) res.push(s[pos++]);
		else {
			if(s[pos] >= res.top()) {
				res.push(s[pos]);
			}
			else {
				while(res.top() > s[pos]) {
					k--;
					res.pop();
					if(res.empty() || !k) break;
				}
				res.push(s[pos]);
			}
			pos++;
		}
	}
	
	string ans = "";
	while(!res.empty()) {ans += res.top(); res.pop();}
	reverse(ans.begin(), ans.end());
	
	int n = ans.length();
	n -= k;
	int sta = n-1;
	for(int i = 0;i < n; i++) {
		if(ans[i] != '0') {
			sta = i;
			break;
		}
	}
	for(int i = sta;i < n; i++) {
		printf("%c", ans[i]);
	}
	puts("");
}

//12347897187194164979
//1       1  1 4164979
