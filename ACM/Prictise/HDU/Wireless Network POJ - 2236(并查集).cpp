#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, d, a, b;
int x[1005], y[1005];
int father[1005];
bool istong[1005][1005], ok[1005];
char choose;

int find(int x) {
	if(x == father[x]) return x;
	else return father[x] = find(father[x]);
}

double dist(int a, int b) {
	return sqrt(pow(double(x[a]-x[b]),2)+pow(double(y[a]-y[b]),2));
}

int main() {
	scanf("%d %d", &n, &d);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		father[i] = i;
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = i+1;j <= n; j++) {
			if(dist(i, j) <= d) istong[i][j] = 1,istong[j][i] = 1;
		}
	}
	
	while(~scanf(" %c", &choose)) {
		if(choose == 'O') {
			scanf("%d", &a);
			ok[a] = 1;
			for(int i = 1;i <= n; i++) {
				if(istong[i][a] && i != a && ok[i]) {
					int u = find(a);
					int v = find(i);
					if(u == v) continue;
					father[u] = v;
				}
			}
		}
		
		if(choose == 'S') {
			scanf("%d %d", &a, &b);
			if(find(a) == find(b)) puts("SUCCESS");
			else puts("FAIL");
		}
		
//		for(int i = 1;i <= n; i++) printf("%d ", father[i]);
//		puts("");
	}
}