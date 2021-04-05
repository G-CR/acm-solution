#include <iostream>
#include <cstring>
using namespace std;

const int N = 10000;
int a, b, c;
int n, f[N], t[N];

int main() {
	while(~scanf("%d %d %d", &a, &b, &c) && (a+b+c)) {
		int n = a + 2*b + 5*c;
		memset(f, 0, sizeof(f));
		memset(t, 0, sizeof(t));
		for(int i = 0; i <= a; i++) f[i] = 1, t[i] = 0;
		
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= 2*b; j += 2) {
				t[i+j] += f[i];
			}
		}
		for(int i = 0; i <= n; i++) f[i] = t[i], t[i] = 0;
		
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= 5*c; j += 5) {
				t[i+j] += f[i];
			}
		}
		for(int i = 0; i <= n; i++) f[i] = t[i], t[i] = 0;
		
		bool ok = 0;
		for(int i = 0; i <= n; i++) {
			if(!f[i]) {
				ok = 1;
				printf("%d\n", i);
				break;
			}
		}
		if(!ok) printf("%d\n", n+1);
	}
}