#include <bits/stdc++.h>
using namespace std;

int T, n, m, u, v;
int father[1005];
set <int> st;

int find(int x) {
	if(x == father[x]) return x;
	return find(father[x]);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		st.clear();
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) father[i] = i;
		while(m--) {
			scanf("%d %d", &u, &v);
			father[find(u)] = find(v);
		}
		
		for(int i = 1;i <= n; i++) {
			int t = find(i);
			st.insert(t);
		}
		printf("%d\n", (int)st.size());
	}
}