#include <bits/stdc++.h>
using namespace std;

int _, n;
int num[200005];
struct node {
	int id, pos;
} a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) num[i] = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i].id);
			a[i].pos = i;
			num[a[i].id]++;
		}
		
		int ans = -1;
		for(int i = 1;i <= n; i++) {
			if(num[i] == 1) {
				for(int j = 1;j <= n; j++) {
					if(a[j].id == i) {ans = a[j].pos; break;}
				}
			}
			if(ans != -1) break;
		}
		
		printf("%d\n", ans);
	}
}