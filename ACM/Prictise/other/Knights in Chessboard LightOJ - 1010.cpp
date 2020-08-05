#include <bits/stdc++.h>
using namespace std;

int _, n, m;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d", &n, &m);
		printf("Case %d: ", ++cas);
		if(n < m) swap(n, m);
		if(m == 1) printf("%d\n", n);
		else if(m == 2) {
			int t = n%4;
			printf("%d\n", n/4*4+(t==0?0:(t>1?4:2)));
		}
		else {
			printf("%d\n", n*m%2?n*m/2+1:n*m/2);
		}	
	}
}