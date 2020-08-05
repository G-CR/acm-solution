#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
	for(int a = 0;a <= 100; a++) {
		for(int b = 0;b <= 100; b++) {
			for(int c = 0;c <= 100; c++) {
				if(a + b + c == 100 && 5*a + 3*b + c/3 == 100 && c%3 == 0) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
}