#include <bits/stdc++.h>
using namespace std;

int n;
int a[503][503];
bool t;
vector <int> now;
int x, y;

void gao() {
	now.clear();
	while(x > 0 && x <= n && y > 0 && y <= n) {
		now.push_back(a[x][y]);
		x--; y++;
	}
	if(t) reverse(now.begin(), now.end());
	t = !t;
	for(int k: now) printf("%d ", k);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i = 1;i <= n; i++) {
		x = i, y = 1;
		gao();
	}
	
	for(int i = 2;i <= n; i++) {
		x = n, y = i;
		gao();
	}
}