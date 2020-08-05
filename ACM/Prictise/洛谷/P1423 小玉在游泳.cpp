#include <bits/stdc++.h>
using namespace std;

double fin, i = 2, now;

int main() {
	cin >> fin;
	int num = 0;
	while(1) {
		now += i;
		i *= 0.98;
		num++;
		if(now >= fin) break;
	}
	printf("%d\n", num);
}