#include <bits/stdc++.h>
using namespace std;

int a, b, n = 7;

int main() {
	int ans = -1, day;
	for(int i = 1;i <= 7; i++) {
		scanf("%d %d", &a, &b);
		if(ans < a+b) {
			ans = a+b;
			day = i;
		}
	}
	printf("%d\n", day);
}