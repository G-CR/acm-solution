#include <bits/stdc++.h>
using namespace std;

int _, n, k;
string s;
vector <int> v;

int main() {
	scanf("%d", &_);
	while(_--) {
		v.clear();
		scanf("%d %d", &n, &k);
		cin >> s;
		int numl = 0, ans = 0;
		bool ok = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == 'L') numl++;
			else {
				ok = 1;
				if(s[i-1] == 'L' || i == 0) ans++;
				else ans += 2;
			}
		}
		
		if(k >= numl) {
			printf("%d\n", 2*((int)s.length()-1)+1);
			continue;
		}
		
		int num = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == 'L' && ((i > 0 && s[i-1] == 'W') || num)) {
				num++;
			}
			else if(s[i] == 'W' && num) {
				v.push_back(num);
				num = 0;
			}
		}
		
		sort(v.begin(), v.end());
		for(int i: v) {
			if(k-i >= 0) {
				ans += 2*i+1;
				k -= i;
			}
			else {
				break;
			}
		}
		if(k) {
			if(ok) {
				ans += 2*k;
			}
			else {
				ans += 2*(k-1)+1;
			}
		}
		
		printf("%d\n", ans);
	}
}