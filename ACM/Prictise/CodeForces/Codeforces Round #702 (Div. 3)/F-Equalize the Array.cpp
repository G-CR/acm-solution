#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[200005];
map <int, int> mp, num;
vector <int> v;

int main() {
	scanf("%d", &_);
	while(_--) {
		mp.clear(); v.clear();
		num.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			mp[a[i]]++;
		}
		
		for(auto i: mp) {
			v.push_back(i.second);
		}
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size(); i++) num[v[i]]++;
		
		int ans = 1e9;
		for(int res = 0; res <= *(v.end()-1); res++) {
			int now = 0;
			for(auto i: num) {
				if(i.first < res) now += i.first * i.second;
				else if(i.first > res) now += (i.first-res) * i.second;
			}
			ans = min(ans, now);
		}
		
		printf("%d\n", ans);
	}
}