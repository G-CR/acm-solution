#include <bits/stdc++.h>
using namespace std;

int l, m, a, b;
bool em[10004];

int main() {
	scanf("%d %d", &l, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &a, &b);
		for(int j = a; j <= b; j++) em[j] = 1;
	}
	
	int ans = 0;
	for(int i = 0;i <= l; i++) {
		if(!em[i]) ans++;
	}
	
	printf("%d\n", ans);
}