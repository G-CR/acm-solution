#include <bits/stdc++.h>
using namespace std;


int main() {
	int num = 0;
	for(int i = 1;i <= 2020; i++) {
		if(i % 4 == 0 && i % 6 == 0) {
			num++;
		}
	}
	printf("%d\n", num);
}