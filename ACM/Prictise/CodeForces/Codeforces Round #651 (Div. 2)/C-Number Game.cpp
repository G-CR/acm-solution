#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		if(n == 1) puts("FastestFinger");
		
		else if(n%2 != 	0) puts("Ashishgup");
		else if(n == 2) puts("Ashishgup");
		else {
			bool ok = 0;
			for(int i = 2;i <= sqrt(n); i++) {
				if(n%i == 0) {
					if(i%2 != 0 && n/i != 2) ok = 1;
					int t = n/i;
					if(t%2 != 0 && n/t != 2) ok = 1;
				}
			}
			if(ok) puts("Ashishgup");
			else puts("FastestFinger");
		}
		
	}
}