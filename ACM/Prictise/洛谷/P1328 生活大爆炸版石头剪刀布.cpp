#include <bits/stdc++.h>
using namespace std;

int win[5][5];
int n, na, nb;
int la[205], lb[205];

int main() {
	win[0][0] = 0; win[0][1] = -1; win[0][2] = 1; win[0][3] = 1; win[0][4] = -1;
	win[1][0] = 1; win[1][1] = 0; win[1][2] = -1; win[1][3] = 1; win[1][4] = -1;
	win[2][0] = -1; win[2][1] = 1; win[2][2] = 0; win[2][3] = -1; win[2][4] = 1;
	win[3][0] = -1; win[3][1] = -1; win[3][2] = 1; win[3][3] = 0; win[3][4] = 1;
	win[4][0] = 1; win[4][1] = 1; win[4][2] = -1; win[4][3] = -1; win[4][4] = 0;
	scanf("%d %d %d", &n, &na, &nb);
	for(int i = 1;i <= na; i++) scanf("%d", &la[i]);
	for(int i = 1;i <= nb; i++) scanf("%d", &lb[i]);
	
	
	int p = 0, q = 0, ansa = 0, ansb = 0;
	for(int i = 1;i <= n; i++) {
		++p, ++q;
		if(win[la[p]][lb[q]] == 1) ansa++;
		else if(win[la[p]][lb[q]] == -1) ansb++;
		if(p == na) p = 0;
		if(q == nb) q = 0;
	}
	printf("%d %d\n", ansa, ansb);
}