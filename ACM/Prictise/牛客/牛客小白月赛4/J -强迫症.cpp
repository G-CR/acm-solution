#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
set <long long> st;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		st.insert(a[i]);
	}
	printf("%d\n", n-(int)st.size());
}