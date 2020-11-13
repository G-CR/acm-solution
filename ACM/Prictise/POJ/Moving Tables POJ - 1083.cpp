#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int _, n, l, r;
int num[405];

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(num, 0, sizeof num);
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d %d", &l, &r);
			if(l > r) swap(l, r);
			if(l % 2 == 0) l--;
			if(r % 2 == 1) r++;
			for(int j = l;j <= r; j++) {
				num[j]++;
			}
		}
		
		int ans = 0;
		for(int i = 1;i <= 400; i++) {
			ans = max(ans, num[i]);
		}
		
		printf("%d\n", ans*10);
	}
}