#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int x1, y1, x2, y2;
	void input() {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}
};
set <int> st;
vector <node> v;
vector <int> li;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		node x; x.input();
		v.push_back(x);
		st.insert(x.x1); st.insert(x.x2);
	}
	
	for(int i: st) li.push_back(i);
	
	
	long long ans = 0;
	for(int i = 1; i < li.size(); i++) {
		vector <pair <int, int> > t;
		for(int j = 0; j < v.size(); j++) {
			if(v[j].x1 <= li[i-1] && v[j].x2 >= li[i]) {
				t.push_back({v[j].y1, v[j].y2});
			}
		}
		
		sort(t.begin(), t.end());
		long long h = 0;
		int l = 0, r = 0;
		
		if(t.size()) {
			int l = t[0].first, r = t[0].second;
			for(int j = 1; j < t.size(); j++) {
				if(t[j].first <= r && t[j].second > r) r = t[j].second;
				else if(t[j].first > r) {
					h += r-l;
					l = t[j].first;
					r = t[j].second;
				}
			}
			h += r-l;
		}
		
		ans += h * (li[i] - li[i-1]);
	}
	
	printf("%lld\n", ans);
}