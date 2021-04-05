#include <bits/stdc++.h>
using namespace std;

int _, n, x;
set <int> st;
int num[200];

int main() {
	scanf("%d", &_);
	while(_--) {
		st.clear();
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			num[x]++;
			st.insert(x);
		}
		
		int ans = 0;
		for(auto i: st) {
			if(num[i*2]) {
				ans += num[i] * num[i*2];
			}
		}
		
		printf("%d\n", ans);
	}
}