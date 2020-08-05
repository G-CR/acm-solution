#include <bits/stdc++.h>
using namespace std;

int t, k, d, n;
int a[105];
set<int> st;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &k, &d);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 107;
		for(int i = 1;i <= n-d+1; i++) {
			st.clear();
			for(int j = i;j <= i+d-1; j++) {
				st.insert(a[j]);
			}
			int t = st.size();
			ans = min(ans, t);
		}
		printf("%d\n", ans);
	}
}