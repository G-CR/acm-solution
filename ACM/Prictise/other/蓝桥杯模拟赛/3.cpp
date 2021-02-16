#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 0;
	for(int a = 1;a <= 10; a++) {
		for(int b = a;b <= 10; b++) {
			for(int c = b;c <= 10; c++) {
				for(int d = c;d <= 10; d++) {
					for(int e = d;e <= 10; e++) {
						num++;
					}
				}
			}
		}
	}
	printf("%d\n", num);
}