#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
int now[100005];
map <string, int> mp;

string to(string s) {
	char a = 'a';
	string now = "";
	map <char, char> cg;
	for(int i = 0; i < s.length(); i++) {
		if(cg.count(s[i])) {
			now += cg[s[i]];
		}
		else {
			cg[s[i]] = a++;
			now += cg[s[i]];
		}
	}
	
	return now;
}

int cnt = 0;

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		cin >> s;
		s = to(s);
		if(mp[s]) now[i] = mp[s];
		else {
			mp[s] = ++cnt;
			now[i] = cnt;
		}
	}
	
	int l, r;
	while (q--) {
		cin >> s;
		s = to(s);
		scanf("%d %d", &l, &r);
		int ans = 0;
		int k = mp[s];
		for(int i = l; i <= r; i++) {
			if(k == now[i]) {
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
}