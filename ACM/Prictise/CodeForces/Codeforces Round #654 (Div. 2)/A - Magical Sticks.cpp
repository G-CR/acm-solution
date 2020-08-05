#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		if(n == 1) puts("1");
		else if(n == 2) puts("1");
		else if(n == 3) puts("2");
		else printf("%d\n", (n+1)/2);
	}
}