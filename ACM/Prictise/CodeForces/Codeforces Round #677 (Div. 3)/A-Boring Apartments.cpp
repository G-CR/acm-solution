#include <bits/stdc++.h>
using namespace std;

int _, x;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &x);
		int ans[] = {0, 1, 3, 6, 10};
		int a = x % 10;
		int num = 0;
		while(x) {
			x /= 10;
			num++;
		}
//		printf("a = %d num = %d\n", a, num);
		printf("%d\n", (a-1)*10+ans[num]);
	}
}