#include <bits/stdc++.h>
using namespace std;

int n, fa[1000005];
map <string, int> mp;

int main() {
	scanf("%d", &n);
	string a, b;
	int cnt = 0;
	for(int i = 1;i <= 2*n; i++) fa[i] = i;
	for(int i = 1;i <= n; i++) {
		cin >> a >> b;
		if(!mp[a]) mp[a] = ++cnt;
		if(!mp[b]) mp[b] = ++cnt;
		fa[mp[b]] = mp[a];
	}
	
	bool ok = 1;
	for(int i = 1;i <= cnt; i++) {
		if(fa[i] == i) {ok = 0; break;}
	}
	if(ok) puts("1");
	else puts("0");
}