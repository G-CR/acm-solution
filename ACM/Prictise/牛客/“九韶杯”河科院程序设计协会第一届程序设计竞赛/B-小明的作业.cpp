#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int a = 0, b = 0;
	int pos = 0, n = s.length();
	while(pos < n) {
		if(s[pos] == 'a' || s[pos] == 'w') {
			vector <char> g;
			g.push_back(s[pos++]);
			while((g[g.size()-1] == 'a' && s[pos] == 'w') || (g[g.size()-1] == 'w' && s[pos] == 'a')) {
				g.push_back(s[pos++]);
			}
			if(g.size() <= 3 && g.size() > 1) a++;
			else if(g.size() > 3) b++;
			g.clear();
		}
		else pos++;
	}
	printf("%d\n%d\n", a, b);
}