#include <bits/stdc++.h>
using namespace std;

int _;
long long n;
string s;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld", &n);
		cin >> s;
		printf("Case %d: ", ++cas);
		int t = n%3;
		if(s == "Alice") {
			if(t == 1) puts("Bob");
			else puts("Alice");
		}
		else {
			if(t == 0) puts("Alice");
			else puts("Bob");
		}
	}
}