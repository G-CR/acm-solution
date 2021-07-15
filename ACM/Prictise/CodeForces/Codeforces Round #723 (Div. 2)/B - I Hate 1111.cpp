#include <bits/stdc++.h>
using namespace std;


int main() {
	int _; scanf("%d", &_); while(_--) {
		int x; scanf("%d", &x);
		
		bool ok = 0;
		for(int i = 0; i < 11; i++) {
			if(111 * i <= x && (x - 111*i) % 11 == 0)
				ok = 1;
		}
		
		puts(ok?"YES":"NO");
	}
}