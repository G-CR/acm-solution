#include <bits/stdc++.h>
using namespace std;

int _, n, m, a[100005];
map <int, int> num;

int main() {
	scanf("%d", &_);
	while(_--) {
		num.clear();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			num[a[i]%m]++;
		}
		
		int ans = 0;
		for (auto i: num) {
			if(i.second == 0) continue;
			int s = i.first;
			int t = m - i.first;
			
			if(s == t || s == 0) {
				num[s] = 0;
				ans++;
			}
			else {
				if(!num[t]) {
					ans += num[s];
					num[s] = 0;
					continue;
				}
				int mi = min(num[s], num[t]);
				if(num[s] > num[t]) num[s]--;
				else if(num[s] < num[t]) num[t]--;
				num[s] -= mi; num[t] -= mi;
				ans++;
				if(num[s] > 0) {
					ans += num[s];
					num[s] = 0;
				}
				if(num[t] > 0) {
					ans += num[t];
					num[t] = 0;
				}
			}
		}
		
		printf("%d\n", ans);
	}
}