#include <bits/stdc++.h>
using namespace std;

int _, n, N;
int a[40][40];

bool checkrow(int r) {
	set <int> vis;
	for(int i = 1;i <= N; i++) {
		if(a[r][i] >= 1 && a[r][i] <= N) vis.insert(a[r][i]);
	}
	return vis.size() == N;
}

bool checkcol(int c) {
	set <int> vis;
	for(int i = 1;i <= N; i++) {
		if(a[i][c] >= 1 && a[i][c] <= N) vis.insert(a[i][c]);
	}
	return vis.size() == N;
}

bool checksqr(int r, int c) {
	set <int> vis;
	for(int i = r;i < r+n; i++) {
		for(int j = c;j < c+n; j++) {
			if(a[i][j] >= 1 && a[i][j] <= N) vis.insert(a[i][j]);
		}
	}
	
	return vis.size() == N;
}

bool check() {
	for(int i = 1;i <= N; i++) if(!checkrow(i)) return 0;
	for(int i = 1;i <= N; i++) if(!checkcol(i)) return 0;
	
	for(int i = 1;i <= N; i += n) {
		for(int j = 1;j <= N; j += n) {
			if(!checksqr(i, j)) return 0;
		}
	}
	return 1;
}

int main() {
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		N = n*n;
		for(int i = 1;i <= N; i++) {
			for(int j = 1;j <= N; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("Case #%d: ", ++cas);
		if(check()) puts("Yes");
		else puts("No");
	}
}