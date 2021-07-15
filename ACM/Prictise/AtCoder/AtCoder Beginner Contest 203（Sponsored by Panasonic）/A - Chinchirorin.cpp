#include <bits/stdc++.h>
using namespace std;

map <int, int> num;

int main() {
	int a, b, c; cin >> a >> b >> c;
	num[a]++; num[b]++; num[c]++;
	if(num.size() == 1) printf("%d\n", a);
	else if(num.size() == 2) {
		if(num[a] == 1) printf("%d\n", a);
		else if(num[b] == 1) printf("%d\n", b);
		else printf("%d\n", c);
	}
	else {
		puts("0");
	}
}