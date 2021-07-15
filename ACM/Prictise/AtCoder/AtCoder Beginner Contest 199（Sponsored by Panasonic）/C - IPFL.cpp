#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

int n, q;
char s[N];

int main() {
	scanf("%d", &n);
	scanf("%s", (s+1));
	bool fan = 0;
	scanf("%d", &q); while(q--) {
		int op, a, b; scanf("%d %d %d", &op, &a, &b);
		if(op == 1) {
			if(!fan) swap(s[a], s[b]);
			else {
				int na = a+n>2*n?a-n:a+n;
				int nb = b+n>2*n?b-n:b+n;
				swap(s[na], s[nb]);
			}
		}
		else {
			fan = !fan;
		}
	}
	
	if(!fan) printf("%s\n", (s+1));
	else {
		for(int i = n+1; i <= 2*n; i++) printf("%c", s[i]);
		for(int i = 1; i <= n; i++) printf("%c", s[i]);
		puts("");
	}
}