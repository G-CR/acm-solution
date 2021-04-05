#include <iostream>
using namespace std;
const int N = 1000;
int n, f[N], t[N];

int main() {
	for(int i = 0; i <= 300; i++) f[i] = 1, t[i] = 0;
	
	for(int i = 2; i <= 17; i++) {
		for(int j = 0; j <= 300; j++) {
			for(int k = 0; k <= 300; k += i*i) {
				t[j+k] += f[j];
			}
		}
		
		for(int j = 0; j <= 300; j++) f[j] = t[j], t[j] = 0;
	}
	
	while(~scanf("%d", &n) && n) {
		printf("%d\n", f[n]);
	}
}