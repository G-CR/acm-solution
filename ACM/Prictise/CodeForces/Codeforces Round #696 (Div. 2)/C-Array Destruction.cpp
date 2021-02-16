#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[2003];
vector <pair <int, int> > ans;
multiset <int> st;

bool check(int ma) {
	for(int i = 1;i <= 2*n; i++) st.insert(a[i]);
	int num = n;
	while(num--) {
		auto it = st.end(); it--;
		int oth = ma - *it;
		st.erase(it);
		auto ex = st.find(oth);
		if(ex == st.end()) return 0;
		st.erase(ex);
		ans.push_back({ma-oth, oth});
		ma = ma-oth;
	}
	
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		scanf("%d", &n);
		for(int i = 1;i <= 2*n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+2*n);
		
		bool ok = 0;
		for(int i = 1;i < 2*n; i++) {
			st.clear();
			ok = check(a[i] + a[2*n]);
			if(ok) break;
			ans.clear();
		}
		
		if(ok) {
			puts("YES");
			printf("%d\n", ans[0].first+ans[0].second);
			for(auto i: ans) {
				printf("%d %d\n", i.first, i.second);
			}
		}
		else {
			puts("NO");
		}
		
	}
}