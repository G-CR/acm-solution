#include <bits/stdc++.h>
using namespace std;

int _;
string a, b;

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> b;
		a = "";
		int n = b.length();
		for(int i = 0;i < n; i += 2) a += b[i];
		a += b[n-1];
		cout << a << endl;
	}
}