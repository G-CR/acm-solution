#include <bits/stdc++.h>
using namespace std;

int bian = 3, dian = 3;

int main() {
	while(bian <= 2020) {
		bian += 2;
		dian++;
	}
	printf("bian = %d dina = %d\n", bian, dian);
}