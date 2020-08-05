#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[100005], b[100005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		for(int i = 1;i <= n; i++) {
			scanf("%d", &b[i]);
		}
		
		int t = 0;
		int ok = 0;
		int fin = 1;
		int jie = 0;
		for(int i = 1;i <= n; i++) {
			if(!ok) {
				if(a[i] == b[i]) continue;
				else {
					ok = 1;
					t = b[i] - a[i];
					if(t < 0) {
						fin = 0; break;
					}
				}
			}
			else {
				if(a[i] == b[i]) {
					jie = 1;
				}
				else {
					if(b[i]-a[i] != t) {fin = 0; break;}
					if(jie) {
						if(a[i] != b[i]) {fin = 0; break;}
					}
				}
			}
		}
		if(fin) puts("YES");
		else puts("NO");
	}
}