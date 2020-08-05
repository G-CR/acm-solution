#include <bits/stdc++.h>
using namespace std;

int _, m, a[100];
char s[100], ans[100], num[30];
vector <int> t;
bool vis[55];

bool cmp(char a, char b) {
	return a > b;
}

bool check() {
	for(int i = 1;i <= m; i++) if(ans[i] == '0') return 0;
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		int n = strlen(s);
		memset(num, 0, sizeof(num));
		for(int i = 0;i < n; i++) num[s[i]-'a']++;
		
		scanf("%d", &m);
		for(int i = 1;i <= m; i++) scanf("%d", &a[i]);
		
		memset(vis, 0, sizeof(vis));
		for(int i = 1;i <= m; i++) ans[i] = '0';
		
		int last = 25;
		while(!check()) {
			t.clear();
			for(int i = 1;i <= m; i++) {
				if(a[i] == 0 && !vis[i]) {
					vis[i] = 1;
					t.push_back(i);
				}
				
			}
			bool ok = 0;
			for(int i = last;i >= 0; i--) {
				if(num[i] >= t.size()) {
					for(int j = 0;j < t.size(); j++) {
						ans[t[j]] = 'a'+i;
					}
					last = i-1;
					break;
				}
			}
			
			for(int i = 1;i <= m; i++) {
				if(a[i]) for(int j = 0;j < t.size(); j++) {
					a[i] -= abs(i-t[j]);
				}
			}
		}
		for(int i = 1;i <= m; i++) printf("%c", ans[i]); puts("");
	}
}