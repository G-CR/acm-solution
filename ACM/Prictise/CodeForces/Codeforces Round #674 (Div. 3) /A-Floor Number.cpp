#include <bits/stdc++.h>
using namespace std;

int _, n, x;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &x);
		if(n <= 2) puts("1");
		else {
			n -= 2;
			printf("%d\n", 1 + int(ceil((double)n/(double)x)));
		}
	}
}