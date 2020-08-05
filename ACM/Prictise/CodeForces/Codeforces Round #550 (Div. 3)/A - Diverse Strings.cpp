#include <bits/stdc++.h>
using namespace std;

char s[200];
int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%s", s+1);
		int n = strlen(s+1);
		sort(s+1, s+1+n);
		bool ok = 1;
		for(int i = 2;i <= n; i++) {
			if(s[i]-s[i-1]!=1) {
				ok = 0; break;
			}
		}
		
		if(ok) puts("Yes");
		else puts("No");
	}
}