#include <iostream>
using namespace std;
const int inf = 100000000;
int n, dis[2002][2002], lowcost[2002], closest[2002];
char s[2002][8];
bool isin[2002];

int getdif(string a, string b) {
	int num = 0;
	for(int i = 0;i < 7; i++) {
		if(a[i] != b[i]) num++;
	}
	return num;
}

int prim() {
	isin[1] = 1;
	for(int i = 1;i <= n; i++) {
		if(i != 1) {
			lowcost[i] = dis[1][i];
			closest[i] = 1;
			isin[i] = 0;
		}
		else lowcost[i] = 0;
	}
	
	for(int i = 1;i <= n; i++) {
		int temp = inf;
		int t = 1;
		for(int j = 1;j <= n; j++) {
			if(!(isin[j]) && (lowcost[j] < temp)) {
				t = j;
				temp = lowcost[j];
			}
		}
		if(t == 1) break;
		isin[t] = 1;
		for(int j = 1;j <= n; j++) {
			if(!(isin[j]) && (dis[t][j] < lowcost[j])) {
				lowcost[j] = dis[t][j];
				closest[j] = t;
			}
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) ans += lowcost[i];
	return ans;
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 1;i <= n; i++) scanf("%s", s[i]);
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				int mon = getdif(s[i], s[j]);
				dis[i][j] = dis[j][i] = mon;
			}
		}
		printf("The highest possible quality is 1/%d.\n", prim());
	}	
}