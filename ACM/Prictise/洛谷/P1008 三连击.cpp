#include <bits/stdc++.h>
using namespace std;


int main() {
	bool ok[10];
	bool ans = 1;
	for(int i = 123;i <= 333; i++) {
		int j = i*2, k = i*3; 
		ans = 1;
		int o = i,p = j,q = k;
		memset(ok, 0 ,sizeof(ok));
		while(o) ok[o%10] = 1,o /= 10;
		while(p) ok[p%10] = 1,p /= 10;
		while(q) ok[q%10] = 1,q /= 10;
		for(int l = 1;l <= 9; l++) if(!ok[l]) {ans = 0; break;}
		if(ans) printf("%d %d %d\n",i, j, k);
	}
}