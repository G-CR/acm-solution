#include <bits/stdc++.h>
using namespace std;

int n, s;

int main() {
	scanf("%d %d", &n, &s);
	if(s < 2*n) puts("NO");
	else {
		puts("YES");
		for(int i = 1;i < n; i++) printf("1 ");
		printf("%d\n", s-n+1);
		printf("%d\n", n);
	}
}