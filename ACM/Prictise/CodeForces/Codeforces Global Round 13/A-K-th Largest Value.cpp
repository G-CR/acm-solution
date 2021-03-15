#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100005];
int num;

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i]) num++;
	}
	
	int x, y;
	while(q--) {
		scanf("%d %d", &x, &y);
		if(x == 1) {
			if(a[y]) num--;
			else num++;
			a[y] = !a[y];
		}
		else {
			if(y <= num) puts("1");
			else puts("0");
		}
	}
}