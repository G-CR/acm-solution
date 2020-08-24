#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, m, x;
vector<pair<int, int> > a, b;
bitset <maxn> bs, ans;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n; i++) {
		scanf("%d", &x);
		a.push_back(make_pair(x, i));
	} 
	for(int i = 0;i < m; i++) {
		scanf("%d", &x);
		b.push_back(make_pair(x, i));
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans.set();
	for(int j = m-1,i = n-1; j >= 0; j--) {
		while(i >= 0 && a[i].first >= b[j].first) {
			bs.set(a[i].second);
			i--;
		}
		ans &= (bs >> b[j].second);
	}
	printf("%d\n", (int)ans.count());
}