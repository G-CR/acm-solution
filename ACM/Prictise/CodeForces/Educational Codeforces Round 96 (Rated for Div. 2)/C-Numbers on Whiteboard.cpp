#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		if(n == 2) {
			puts("2");
			puts("1 2");
			continue;
		}
		if(n == 3) {
			puts("2");
			puts("1 3");
			puts("2 2");
			continue;
		}
		puts("2");
		printf("%d %d\n", n-2, n);
		int a = n-1, b = n-1;
		printf("%d %d\n", a, b);
		a -= 2;
		while(1) {
			printf("%d %d\n", a, b);
			if(a == 1 && b == 3) break;
			a --; b --;
		}
	}
}