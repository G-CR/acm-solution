#include <bits/stdc++.h>
using namespace std;

int _, n, m;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		if(n == 1) puts("0");
		else if(n == 2) printf("%d\n", m);
		else {
			printf("%d\n", 2*m);
		}
	}
}