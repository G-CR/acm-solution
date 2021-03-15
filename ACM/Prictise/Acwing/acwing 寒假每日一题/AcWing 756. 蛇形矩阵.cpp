#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[102][102];
int tx[] = {0,1,0,-1};
int ty[] = {1,0,-1,0};

int main() {
	scanf("%d %d", &n, &m);
	int num = 1;
	int i = 1, j = 1, pos = 0;
	while(num <= n*m) {
		a[i][j] = num++;
		if(i+tx[pos]>n || i+tx[pos]<1 || j+ty[pos]>m || j+ty[pos]<1 || a[i+tx[pos]][j+ty[pos]])
			pos = (pos+1)%4;
		i += tx[pos]; j += ty[pos];
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}