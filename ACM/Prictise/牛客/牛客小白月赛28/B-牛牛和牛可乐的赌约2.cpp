#include <bits/stdc++.h>
using namespace std;

int _, x, y;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &x, &y);
		if(abs(x-y)%3 == 0) puts("awsl");
		else puts("yyds");
	}
}