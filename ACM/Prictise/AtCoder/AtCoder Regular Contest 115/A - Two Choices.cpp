#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int n, m;
char s[N][22];
int ji = 0, ou = 0;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
		int num = 0;
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '1') num++;
		}
		if(num % 2) ji++;
		else ou++;
	}
	
	printf("%lld\n", 1ll*ji*ou);
}