#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
vector <int> p;

bool check(int p) {
	if(p + 4 > s.length()) return 0;
	if(s[p] == 'm')
		if(s[p+1] == 'o')
			if(s[p+2] == 'c') 
				if(s[p+3] == 'h')
					if(s[p+4] == 'a')
						return 1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(check(i)) {
			p.push_back(i);
		}
	}
	
	if(p.size() < k) {
		puts("poor Mocha");
	}
	else {
		puts("Mocha suki!");
		int l = 0, r = l + k - 1;
		int ans = 1e9;
		while(r < p.size()) {
			ans = min(ans, p[r] - p[l] + 5);
			l++, r++;
		}
		printf("%d\n", ans);
	}
}