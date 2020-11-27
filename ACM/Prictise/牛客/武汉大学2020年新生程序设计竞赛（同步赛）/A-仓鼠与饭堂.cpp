#include <bits/stdc++.h>
using namespace std;

int _, n, m;
double w;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		bool ok = 1;
		double sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lf", &w);
			if(w > m) ok = 0;
			m -= 0.7*w;
		}
		if(ok) puts("yes");
		else puts("no");
	}
}