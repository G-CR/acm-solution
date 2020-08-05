#include <bits/stdc++.h>
using namespace std;

int f[1005], n;

int main() {
	f[1] = 1;
	f[2] = 2;
	for(int i = 3;i <= 1000; i++) {
		for(int j = i/2;j >= 1; j--) {
			f[i] += f[j];
		}
		f[i]++;
	}
	scanf("%d", &n);
	printf("%d\n", f[n]);
}