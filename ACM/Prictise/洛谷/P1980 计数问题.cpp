#include <bits/stdc++.h>
using namespace std;

int num, n, x;

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 1;i <= n; i++) {
		int now = i;
		while(now) {
			int t = now%10; now /= 10;
			if(t == x) num++;
		}
	}
	printf("%d\n", num);
}