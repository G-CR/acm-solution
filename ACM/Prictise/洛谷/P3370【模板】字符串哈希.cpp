#include <bits/stdc++.h>
using namespace std;

int base = 17, mod = 998244353;
int n;

int gethash(string s) {
	int res = 0;
	for(int i = 0; i < s.length(); i++) {
		res = (res * base + s[i]) % mod;
	}
	return res;
}
set <int> st;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		string s; cin >> s;
		st.insert(gethash(s));
	}
	printf("%lu\n", st.size());
}