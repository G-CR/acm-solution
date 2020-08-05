#include <bits/stdc++.h>
using namespace std;

int _, n, x;
set <int> st;

int main() {
	scanf("%d", &_);
	while(_--) {
		st.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			st.insert(x);
		}
		printf("%d\n", (int)st.size());
	}
}