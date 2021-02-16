#include <bits/stdc++.h>
using namespace std;

int _, n, x;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int num1 = 0, num2 = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(x == 1) num1++;
			else if(x == 2) num2++;
		}
		num2 %= 2;
		if(num2 == 1 && num1 >= 2) num2 = 0, num1 -= 2;
		if(num1 % 2 || num2 % 2) {puts("NO"); continue;}
		puts("YES");
	}
}