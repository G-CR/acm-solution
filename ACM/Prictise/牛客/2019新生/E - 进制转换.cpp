#include <bits/stdc++.h>
using namespace std;

int n, k;
stack<int> sta;

int main() {
	scanf("%d %d", &n, &k);
	while(n) {
		int t = n % k;
		sta.push(t);
		n /= k;
	}
	while(!sta.empty()) {
		int t = sta.top(); sta.pop();
		printf("%d", t);
	}
}