#include <iostream>
using namespace std;

const int N = 200;
int n, f[N], t[N];

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 0; i <= n; i++) f[i] = 1, t[i] = 0;
		
		for(int i = 2; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				for(int k = 0; k <= n; k += i) {
					t[j+k] += f[j];
				}
			}
			
			for(int j = 0; j <= n; j++) f[j] = t[j], t[j] = 0;
		}
		
		printf("%d\n", f[n]);
	}
}