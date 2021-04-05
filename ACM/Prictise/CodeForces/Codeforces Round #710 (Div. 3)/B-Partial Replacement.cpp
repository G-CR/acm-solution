#include <bits/stdc++.h>
using namespace std;

int _, n, k;
string s;
vector <int> g;

int main() {
	scanf("%d", &_);
	while(_--) {
		g.clear();
		scanf("%d %d", &n, &k);
		cin >> s;
		
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '*') {
				g.push_back(i);
			}
		}
		
		if(g.size() == 1) {
			puts("1");
			continue;
		}
		
		int ans = 2, pos = g[0] + k;
		for(int i = 1; i < g.size()-1; i++) {
			if(g[i+1] > pos) {
				ans++;
				pos = g[i] + k;
			}
		}
		
		printf("%d\n", ans);
	}
}