#include <bits/stdc++.h>
using namespace std;

int q;
int a[105];

int main() {
	scanf("%d", &q);
	while(q--) {
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		int ans = 1; bool ok = 0;
		for(int i = 2;i <= n; i++) {
			if(a[i] - a[i-1] == 1) {
				ok = 1;
				puts("2");
				break;
			} 
		}
		if(!ok) puts("1");
	}
}