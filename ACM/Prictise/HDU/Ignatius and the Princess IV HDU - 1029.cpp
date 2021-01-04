#include <iostream>
#include <map>
using namespace std;

int n, a;
map <int, int> vis;

int main() {
	while(~scanf("%d", &n)) {
		vis.clear();
		int num = (n+1)/2, ans;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a);
			vis[a]++;
			if(vis[a] >= num) {
				ans = a;
			}
		}
		printf("%d\n", ans);
	}
}