#include <bits/stdc++.h>
using namespace std;

set <int> st;
int n, x;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		st.insert(x);
	}
	printf("%lu\n", st.size());
	for(int i: st) {
		printf("%d ", i);
	}
}