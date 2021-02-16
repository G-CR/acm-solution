#include <bits/stdc++.h>
using namespace std;

int a, b, t;

int main() {
	scanf("%d %d %d", &a, &b, &t);
	b += t;
	while(b >= 60) {
		a++;
		b -= 60;
	}
	
	printf("%d\n%d\n", a, b);
	return 0;
}