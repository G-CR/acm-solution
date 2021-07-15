#include <bits/stdc++.h>
using namespace std;

string s;
int vis[10];

bool check(int k) {
	map <int, bool> mp;
	int num = 4;
	while(num--) {
		mp[k%10] = 1;
		k /= 10;
	}
	for(int i = 0; i < 10; i++) {
		if((vis[i] == 1 && !mp[i]) || (vis[i] == -1 && mp[i])) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'o') vis[i] = 1;
		else if(s[i] == 'x') vis[i] = -1;
	}
	
	int ans = 0;
	for(int i = 0; i <= 9999; i++) {
		ans += check(i);
	}
	
	cout << ans << "\n";
}