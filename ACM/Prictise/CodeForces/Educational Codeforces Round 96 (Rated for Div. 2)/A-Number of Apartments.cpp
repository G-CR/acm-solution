#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int a = 0, b = 0, c = 0;
		bool ok = 0;
		for(int i = 0;i <= n/3; i++) {
			for(int j = 0;j <= n/5; j++) {
				if((n-i*3-j*5)%7 == 0) {
					ok = 1;
					a = i; b = j; c = (n-i*3-j*5)/7;
					break;
				}
			}
			if(ok) break;
		}
		
		if(!ok) puts("-1");
		else printf("%d %d %d\n", a, b, c);
	}
}