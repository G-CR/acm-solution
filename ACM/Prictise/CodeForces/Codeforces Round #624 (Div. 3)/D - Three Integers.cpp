#include <bits/stdc++.h>
using namespace std;

int a, b, c, t;
set <int> st[20004];

void init() {
	for(int i = 1;i <= 20000; i++) {
		for(int j = 1;j*j <= i; j++) {
			if(i % j == 0) {
				st[i].insert(j);
				st[i].insert(i/j);
			}
		}
	}
}

int main() {
	init();
	scanf("%d", &t);
	while(t--) {
		int A, B, C, ans = 60000, n1, n2, n3;
		scanf("%d %d %d", &a, &b, &c);
		for(int i = 1;i <= 20000; i++) {
			n3 = abs(c-i);
			for(auto j = st[i].begin();j != st[i].end(); j++) {
				n2 = abs(b-*j);
				for(auto k = st[*j].begin();k != st[*j].end(); k++) {
					n1 = abs(a-*k);
					if(n1+n2+n3 < ans) {
						ans = n1+n2+n3;
						A = *k; B = *j; C = i;
					}
				}
			}
		}
		printf("%d\n%d %d %d\n", ans, A, B, C);
	}
	
}