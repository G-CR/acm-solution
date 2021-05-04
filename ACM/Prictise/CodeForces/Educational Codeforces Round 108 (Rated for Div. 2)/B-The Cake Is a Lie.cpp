#include <bits/stdc++.h>
using namespace std;

int _, n, m, k;

int main() {
	scanf("%d", &_); while(_--) {
		scanf("%d %d %d", &n, &m, &k);
		n--; m--;
		if(n + (n+1)*m == k) puts("YES");
		else puts("NO");
	}
}