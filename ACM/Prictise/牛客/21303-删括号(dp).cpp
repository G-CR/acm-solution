#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[103][103];

int dfs(int p1, int p2) {
	if(p2 >= t.length()) return 1;
	else if(p1 >= s.length()) return 0;
	if(~dp[p1][p2]) return dp[p1][p2];
	int ans = 0;
	if(s[p1] == t[p2]) {
		ans = max(ans, dfs(p1+1, p2+1));
	}
	
	if(s[p1] == '(') {
		int num = 0;
		for(int i = p1; i < s.length(); i++) {
			if(s[i] == '(') num++;
			else num--;
			if(num == 0) {
				ans = max(ans, dfs(i+1, p2));
				break;
			}
		}
	}
	
	return dp[p1][p2] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> s >> t;
	puts(dfs(0,0)?"Possible":"Impossible");
}