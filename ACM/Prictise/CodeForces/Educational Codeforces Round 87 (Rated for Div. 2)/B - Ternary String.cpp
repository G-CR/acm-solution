#include <bits/stdc++.h>
using namespace std;

string s;
int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		int n = s.length();
		int pos[4], res[4];
		int ans = 200005;
		pos[1] = -1; pos[2] = -1; pos[3] = -1;
		
		for(int i = 0;i < n; i++) {
			if(s[i] == '1') pos[1] = i;
			if(s[i] == '2') pos[2] = i;
			if(s[i] == '3') pos[3] = i;
			if(pos[1] != -1 && pos[2] != -1 && pos[3] != -1) {
				res[1] = pos[1]; res[2] = pos[2]; res[3] = pos[3];
				sort(res+1, res+4);
				ans = min(ans, res[3]-res[1]+1);
			}
		}
		if(ans == 200005) ans = 0;
		printf("%d\n", ans);
	}
}