#include <iostream>
#include <cstdio>
using namespace std;

int _;
int a[10][10], b[10][10], p[10][10];
int lim = 1 << 6;

void change(int i, int j) {
	a[i][j] = !a[i][j];
	a[i-1][j] = !a[i-1][j];
	a[i][j-1] = !a[i][j-1];
	a[i+1][j] = !a[i+1][j];
	a[i][j+1] = !a[i][j+1];
}

bool check() {
	for(int i = 1;i <= 5; i++) {
		for(int j = 1;j <= 6; j++) {
			if(a[i][j]) return 0;
		}
	}
	return 1;
}

void ma() {
	for(int i = 1;i <= 5; i++) {
		for(int j = 1;j <= 6; j++) {
			a[i][j] = b[i][j];
		}
	}
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		for(int i = 1;i <= 5; i++) {
			for(int j = 1;j <= 6; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		
		for(int i = 0;i < lim; i++) {
			ma();
			int num = 6, pos = 7, t = i;
			while(num--) {
				p[1][--pos] = t&1;
				t >>= 1;
			}
			for(int j = 1;j <= 6; j++) {
				if(p[1][j]) change(1, j);
			}
			
			for(int j = 2;j <= 5; j++) {
				for(int k = 1;k <= 6; k++) {
					p[j][k] = 0;
					if(a[j-1][k]) {
						change(j, k);
						p[j][k] = 1;
					}
				}
			}
			
			if(check()) break;
		}
		printf("PUZZLE #%d\n", ++cas);
		for(int i = 1;i <= 5; i++) {
			for(int j = 1;j <= 6; j++) {
				printf("%d ", p[i][j]);
			}
			puts("");
		}
	}
}