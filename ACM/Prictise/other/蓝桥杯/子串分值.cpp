#include <bits/stdc++.h>
using namespace std;

string s;
vector <int> g[30];

int main() {
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++) {
		g[s[i]-'a'].push_back(i);
	}
	
	long long ans = 0;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int pos = g[i][j];
			int l, r;
			if(j == 0) l = pos+1;
			else l = pos - g[i][j-1];
			
			if(j == g[i].size()-1) r = n-pos;
			else r = g[i][j+1]-pos;
			ans += l * r;
		}
	}
	
	printf("%lld\n", ans);
}