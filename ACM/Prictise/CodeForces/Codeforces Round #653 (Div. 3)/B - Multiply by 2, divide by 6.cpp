#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int cnt = 0;
		bool ok = 1;
		while(n > 1) {
			if(n % 6 == 0) cnt++, n /= 6;
			else if(n % 3 == 0) cnt+=2, n/=3;
			else {
				ok = 0;
				break;
			}
		}
		if(!ok) puts("-1");
		else printf("%d\n", cnt);
	}
}