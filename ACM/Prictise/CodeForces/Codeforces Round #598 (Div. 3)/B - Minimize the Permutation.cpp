#include <bits/stdc++.h>
using namespace std;

bool ok[105];
int q, n;
int a[105];

int main() {
	scanf("%d", &q);
	while(q--) {
		memset(ok, 0, sizeof(ok));
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int cnt = 1;
		for(int p = 1;p <= n; p++){
			for(int i = 1;i <= n; i++) {
				if(a[i] == p) {
					for(int j = i;j >= 2;j--) {
						if(ok[j-1]||a[j]>a[j-1]) break;
						swap(a[j], a[j-1]);
						ok[j-1] = 1;
					}
					break;
				}
			}
		}
		
		for(int i = 1;i <= n; i++) printf("%d ", a[i]);
		puts("");
	}
}