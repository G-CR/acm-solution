#include <bits/stdc++.h>
using namespace std;

int l, r;
bool ok[10];

int main() {
	scanf("%d %d", &l, &r);
	bool fin = 0;
	int ans;
	for(int i = l;i <= r; i++) {
		memset(ok,0,sizeof(ok));
		int j = i;
		while(j > 0) {
			int t = j % 10;
			if(ok[t]) break;
			else ok[t] = 1;
			j /= 10;
		}
		if(j == 0) {
			fin = 1;
			ans = i;
			break;
		}
	}
	if(fin) printf("%d\n", ans);
	else puts("-1");
}