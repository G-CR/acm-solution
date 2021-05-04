#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 0;
	for(int i = 1; i <= 2021; i++) {
		int k = i;
		while(k) {
			if(k % 10 == 6) num++;
			k /= 10;
		}
		
	}
	printf("%d\n", num);
}