#include <bits/stdc++.h>
using namespace std;

int h, app[11];

int main() {
	for(int i = 1;i <= 10; i++) {
		scanf("%d", &app[i]);
	}
	scanf("%d", &h);
	h += 30;
	
	int ans = 0;
	for(int i = 1;i <= 10; i++) {
		if(app[i] <= h) ans++;
	}
	
	printf("%d\n", ans);
}