#include <bits/stdc++.h>
using namespace std;

int n, x;
bool ok[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n-1; i++) {
		scanf("%d", &x);
		ok[x] = 1;
	}
	for(int i = 1;i <= n; i++) if(!ok[i]) {printf("%d\n", i); return 0;}
}