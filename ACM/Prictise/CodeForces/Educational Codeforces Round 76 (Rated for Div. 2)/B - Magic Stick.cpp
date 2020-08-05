#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll x, y;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &x, &y);
		if(x == y) puts("YES");
		else {
			if(x == 1) puts("NO");
			else if(x == 2 && (y != 1 && y != 3)) puts("NO");
			else if(x == 3 && (y != 1 && y != 2 && y != 3)) puts("NO");
			else puts("YES");
		}
	}
}