#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005], b[200005];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	} sort(a+1, a+1+n);
	for(int i = 1;i <= m; i++) {
		scanf("%d", &b[i]);
	} sort(b+1, b+1+m);
	
	int pos1 = 1, pos2 = 1, ans = 0;
	while(pos1 <= n && pos2 <= m) {
		if(a[pos1] > b[pos2]) {
			ans++;
			pos1++; pos2++;
		}
		else {
			pos1++;
		}
	}
	
	printf("%d\n", ans);
}