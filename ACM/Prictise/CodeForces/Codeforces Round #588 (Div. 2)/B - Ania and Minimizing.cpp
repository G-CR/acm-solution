#include <bits/stdc++.h>
using namespace std;

char s[200005];
int k,n;

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s+1);
	if(!k) return puts(s+1), 0;
	if(n == 1) return puts("0"), 0;
	
	int j = 0;
	if(s[1] != '1') {
		j++;
		s[1] = '1';
	}
	for(int i = 2;i <= n; i++) {
		if(j == k) break;
		if(s[i] != '0') {
			s[i] = '0';
			j++;
		}
	}
	printf("%s\n", s+1);
}