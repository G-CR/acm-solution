#include <bits/stdc++.h>
using namespace std;

int _;
string a, b, c;

string str(int l, int r) {
	string k = "";
	for(int i = l; i <= r; i++) {
		k += b[i];
	}
	return k;
}

bool isok(int pos) {
	for(int i = pos, j = 0; j < c.length(); i++, j++) {
		if(i == a.length()) return 0;
		if(a[i] != c[j]) return 0;
	}
	return 1;
}

bool check() {
	for(int i = 0; i < a.length(); i++) {
		if(a[i] == c[0]) {
			if(isok(i)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> a >> b;
		int ans = a.length() + b.length();
		for(int len = 1; len <= b.length(); len++) {
			int l = 0, r = l + len - 1;
			while(r < b.length()) {
				c = str(l, r);
//				cout << c << endl;
				if(check()) {
					ans = min(ans, (int)((a.length()-c.length())+(b.length()-c.length())));
				}
				l++, r++;
			}
		}
		
		printf("%d\n", ans);
	}
}