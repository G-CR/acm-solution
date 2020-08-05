#include <bits/stdc++.h>
using namespace std;

map <pair<int,int>,int> ok, num;
int t, n;
char a[200005];
pair<int,int> fin;

int main() {
	scanf("%d", &t);
	while(t--) {
		ok.clear();
		ok[make_pair(0, 0)] = 1;
		num[make_pair(0, 0)] = 0;
		int x = 0, y = 0, ans = 2000000;
		fin.first = -1;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf(" %c", &a[i]);
			if(a[i] == 'L') x--;
			if(a[i] == 'R') x++;
			if(a[i] == 'U') y++;
			if(a[i] == 'D') y--;
			
			if(ok[make_pair(x,y)] == 0) {
				ok[make_pair(x, y)] = 1;
				num[make_pair(x, y)] = i;
			}
			
			else {
				if(ans > i-num[make_pair(x,y)]) {
					ans = i-num[make_pair(x,y)];
					fin.first = num[make_pair(x,y)];
					fin.second = i;
				}
				num[make_pair(x, y)] = i;
			}
		}
		if(fin.first != -1) printf("%d %d\n", fin.first+1, fin.second);
		else puts("-1");
	}
}