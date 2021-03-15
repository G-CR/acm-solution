#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	int da = 0, ang = 0;
	for(int i = 1;i <= 7; i++) {
		scanf("%d %d", &a, &b);
		if(a+b > 8 && a+b > ang) {
			da = i;
			ang = a+b;
		}
	}
	
	printf("%d\n", da);
}