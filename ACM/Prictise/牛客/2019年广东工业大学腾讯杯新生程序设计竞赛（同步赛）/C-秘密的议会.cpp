#include <bits/stdc++.h>
using namespace std;

int T;
char s[105];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		int n = strlen(s+1), numy = 0, numn = 0;
		for(int i = 1;i <= n; i++) {
			if(s[i] == 'y' || s[i] == 'Y') numy++;
			if(s[i] == 'n' || s[i] == 'N') numn++;
		}
		if(numy >= n/2) puts("pmznb");
		else if(numn >= n/2) puts("lyrnb");
		else puts("wsdd");
	}
}