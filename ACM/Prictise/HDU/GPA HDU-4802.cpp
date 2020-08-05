#include <bits/stdc++.h>
using namespace std;

map <string, double> mp;
int n, score;
string level;

void init() {
	mp["A"] = 4.0; mp["A-"] = 3.7; mp["B+"] = 3.3;
	mp["B"] = 3.0; mp["B-"] = 2.7; mp["C+"] = 2.3;
	mp["C"] = 2.0; mp["C-"] = 1.7; mp["D"] = 1.3;
	mp["D-"] = 1.0; mp["F"] = 0;
}

int main() {
	init();
	while(~scanf("%d", &n)) {
		double ans = 0, sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &score);
			cin >> level;
			if(level == "P" || level == "N") continue;
			sum += score;
			ans += score * mp[level];
		}
		printf("%.2lf\n",sum == 0?0:ans/sum);
	}
}