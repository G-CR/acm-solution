#include <bits/stdc++.h>
using namespace std;

string s[105], t, ans;
int n, m;
bool ok[105];

bool check() {
	int n = t.length();
	if(n%2) return 0;
	for(int i = 0;i < n/2; i++) {
		if(t[i] != t[n-1-i]) return 0;
	}
	return 1;
}

void daoru() {
	int n = t.length()/2;
	for(int i = 0;i < n; i++) ans += t[i];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n; i++) cin >> s[i];

	for(int i = 0;i < n; i++) {
		if(ok[i]) continue;
		for(int j = i+1;j < n; j++) {
			if(ok[j]) continue;
			t = "";
			t += s[i]; t += s[j];
			if(check()) {
				daoru();
				ok[i] = 1; ok[j] = 1;
				break;
			}
		}
	}
	
	string mid = "";
	bool Mid = 1;
	int num = 0;
	for(int i = 0;i < n; i++) {
		if(!ok[i]) {
			Mid = 1;
			t = s[i];
			num = t.length();
			for(int j = 0;j < num; j++) {
				if(t[j] != t[num-1-j]) {Mid = 0; break;}
			}
			if(Mid) {mid = s[i]; break;}
		}
	}
	if(!Mid) num = 0;
	
	int fin = ans.length(); printf("%d\n", fin*2+num);
	for(int i = 0;i < fin; i++) printf("%c", ans[i]);
	cout << mid;
	for(int i = fin-1;i >= 0; i--) printf("%c", ans[i]);
	puts("");
}