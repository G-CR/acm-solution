#include <bits/stdc++.h>
using namespace std;

int n;
long long a[25];
string s;

void dfs(int pos, long long now, vector <char> ans) {
	if(pos == n) {
		if(now == a[n]) {
			for(char i: ans) s += i;
		}
		return;
	}
	ans.push_back('-');
	dfs(pos+1, now-a[pos], ans);
	ans.pop_back();
	
	ans.push_back('+');
	dfs(pos+1, now+a[pos], ans);
	ans.pop_back();
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	vector <char> res;
	dfs(2, a[1], res);
	if(s.length()) {
		printf("%d\n", (int)s.length()/(n-2));
		for(int i = 0;i < s.length(); i++) {
			printf("%c", s[i]);
			if((i+1)%(n-2)==0) puts("");
		}
	}
	else puts("0");
}