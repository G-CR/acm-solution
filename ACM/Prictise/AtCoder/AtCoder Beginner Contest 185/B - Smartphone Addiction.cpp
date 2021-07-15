#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[1003], b[1003];

int main() {
	scanf("%d %d %d", &n, &m, &t);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	
	int now = 0; bool ok = 1;
	int bat = n;
	for(int i = 1; i <= m; i++) {
		int cha = a[i] - now;
		bat -= cha;
		if(bat <= 0) {
			ok = 0;
			break;
		}
		bat += b[i] - a[i];
		bat = min(bat, n);
		now = b[i];
	}
	bat -= t - b[m];
	if(bat <= 0) ok = 0;
	
	puts(ok?"Yes":"No");
}