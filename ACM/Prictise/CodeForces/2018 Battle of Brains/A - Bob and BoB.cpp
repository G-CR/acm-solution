#include <bits/stdc++.h>
using namespace std;

int T, n, a, b, c, d;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
		if((a+b+c+d)*2 >= n+1) puts("Yes");
		else puts("No");
	}
}