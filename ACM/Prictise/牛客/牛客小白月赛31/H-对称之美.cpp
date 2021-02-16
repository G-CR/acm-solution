#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;
struct node {
	bool a[30];
} vis[103];

bool check(int p, int q) {
	for(int i = 0;i < 26; i++) {
		if(vis[p].a[i] && vis[q].a[i]) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			cin >> s;
			for(int j = 0;j < 26; j++) vis[i].a[j] = 0;
			for(int j = 0;j < s.length(); j++) {
				vis[i].a[s[j]-'a'] = 1;
			}
		}
		bool ok = 1;
		for(int i = 1;i <= n/2; i++) {
			if(!check(i, n-i+1)) {
				ok = 0;
				break;
			}
		}
		
		if(ok) puts("Yes");
		else puts("No");
	}
}