#include <bits/stdc++.h>
using namespace std;

int _, a, b, c, d;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(b+c>a+d) puts("AB//CD");
		else puts("AB//DC");
	}
}