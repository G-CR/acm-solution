#include <bits/stdc++.h>
using namespace std;

int k, n, a[105];
set <int> st;
vector <int> vc;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		int t = st.size();
		st.insert(a[i]);
		if(t < st.size()) vc.push_back(i);
	}
	if(st.size() < k) puts("NO");
	else {
		puts("YES");
		for(int i = 0;i < k; i++) printf("%d ", vc[i]);
	}
}