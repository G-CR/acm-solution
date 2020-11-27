#include <bits/stdc++.h>
using namespace std;

int _, x, y;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &x, &y);
		if(abs(x-y) <= 1) {
			printf("%d\n", x+y);
		}
		else {
			printf("%d\n", x+y+abs(x-y)-1);
		}
	}
}