#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
char s[70], a[35];

int main() {
	scanf("%d %lld", &n, &k);
	scanf("%s", s+1);
	int n = strlen(s+1);
	int j = n;
	for(int i = 1;i <= n; i++) {
		a[j--] = s[i];
	}
	
	for(int i = n+1;i <= 2*n; i++) {
		s[i] = a[++j];
	}
	
	if(k <= 2*n) printf("%c\n", s[k]);
	else {
		k %= 2*n;
		if(k == 0) k = 2*n;
		printf("%c\n", s[k]);
	}
}