#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	bool ok = 0;
	for(int i = 1;i <= n; i++) {
		bool now = ok;
		for(int j = 1;j <= n; j++) {
			printf("%d", now);
			now = !now;
		}
		puts("");
		ok = !ok;
	}
	
}