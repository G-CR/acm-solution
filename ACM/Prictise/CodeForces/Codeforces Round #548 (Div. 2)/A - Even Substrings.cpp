#include <bits/stdc++.h>
using namespace std;

int n;
char c;

int main() {
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1;i <= n; i++) {
		scanf(" %c", &c);
		int a = c-'0';
		if(a%2 == 0) {
			sum += i;
		}
	}
	
	printf("%d\n", sum);
}