#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", 2*max(a,b)+min(a, b));
	}
}