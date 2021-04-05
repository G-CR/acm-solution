#include <bits/stdc++.h>
using namespace std;

int _, n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		if(n % 2) {
			printf("1 %d %d\n", n/2, n/2);
		}
		else {
			if(n % 4 == 0) {
				printf("%d %d %d\n", n/4, n/4, n/2);
			}
			else {
				printf("2 %d %d\n", (n-2)/2, (n-2)/2);
			}
		}
	}
}