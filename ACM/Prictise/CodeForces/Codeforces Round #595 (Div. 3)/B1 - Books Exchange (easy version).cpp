#include <bits/stdc++.h>
using namespace std;

int q;
int p[205], a[205];

int main() {
	scanf("%d", &q);
	while(q--) {
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &p[i]);
		}
		
		int t, ans;
		for(int i = 1;i <= n; i++) {
			t = p[i]; ans = 1;
			while(t != i) {
				int k = t;
				t = p[k];
				ans++;
			}
			a[i] = ans;
		}
		
		for(int i = 1;i <= n; i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
}