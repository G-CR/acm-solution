#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> ans;

int main() {
	cin >> s;
	int n = s.length();
	
	int head = 0, tail = n-1;
	while(head < tail) {
		if(s[head] == '(' && s[tail] == ')') {
			ans.push_back(head+1);
			ans.push_back(tail+1);
			head++, tail--;
		}
		else if(s[head] == ')') head++;
		else if(s[tail] == '(') tail--;
	}
	if(ans.size()) puts("1");
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for(int i = 0;i < ans.size(); i++) printf("%d ", ans[i]);
	puts("");
}