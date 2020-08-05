#include <bits/stdc++.h>
using namespace std;

int n, q, r, c, ans;
bool vis[3][100005];

int check1(int r, int c) {
	if(r < 1 || r > 2 || c < 1 || c > n) return 0;
	if(vis[r][c]) return 1;
	return 0;
}

int check2(int r, int c) {
	if(r < 1 || r > 2 || c < 1 || c > n) return 0;
	if(vis[r][c]) return -1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &q);
	while(q--) {
		scanf("%d %d", &r, &c);
		vis[r][c] = vis[r][c] == 1?0:1;
		if(vis[r][c]) {
			ans += check1(r+1, c-1);
			ans += check1(r+1, c);
			ans += check1(r+1, c+1);
			ans += check1(r-1, c-1);
			ans += check1(r-1, c);
			ans += check1(r-1, c+1);
		}
		else {
			ans += check2(r+1, c-1);
			ans += check2(r+1, c);
			ans += check2(r+1, c+1);
			ans += check2(r-1, c-1);
			ans += check2(r-1, c);
			ans += check2(r-1, c+1);
		}
		if(ans > 0) puts("No");
		else puts("Yes");
	}
}