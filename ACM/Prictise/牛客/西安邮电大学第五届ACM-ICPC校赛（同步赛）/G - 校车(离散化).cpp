#include <bits/stdc++.h>
using namespace std;

int _, n;
int road[100005][2], num[200005];
set <int> st;
map <int, int> mp;

int main() {
	scanf("%d", &_);
	while(_--) {
		mp.clear(); st.clear();
		memset(num, 0, sizeof(num));
		memset(road, 0, sizeof(road));
		
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d %d", &road[i][0], &road[i][1]);
			st.insert(road[i][0]);
			st.insert(road[i][1]);
		}
		
		int cnt = 0;
		for(auto i = st.begin(); i != st.end(); i++) {
			mp[*i] = ++cnt;
		}
		
		for(int i = 1;i <= n; i++) {
			int l = mp[road[i][0]];
			int r = mp[road[i][1]];
			num[l]++;
			num[r]--;
		}
		
		int sum = 0, ans = 0;
		for(int i = 1;i <= 2*n; i++) {
			sum += num[i];
			ans = max(ans, sum);
		}
		
		printf("%d %d\n", (int)st.size(), ans);
	}
}