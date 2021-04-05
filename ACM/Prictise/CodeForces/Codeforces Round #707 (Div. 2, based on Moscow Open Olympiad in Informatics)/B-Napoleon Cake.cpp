#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[200005], pre[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) pre[i] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			pre[max(1, i-a[i]+1)] += 1;
			pre[i+1] += -1;
		}
		for(int i = 1; i <= n; i++) {
			pre[i] = pre[i-1] + pre[i];
		}
		
		for(int i = 1; i <= n; i++) if(pre[i]) printf("1 ");
		else printf("0 ");
		puts("");
	}
}