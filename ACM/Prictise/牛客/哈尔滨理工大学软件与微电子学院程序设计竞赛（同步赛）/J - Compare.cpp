#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	if(n > m) puts(">");
	else if(n < m) puts("<");
	else {
		bool ok = 0;
		for(int i = 0;i < n; i++) {
			if(a[i] > b[i]) {
				puts(">"); ok = 1;
				break;
			}
			else if(a[i] < b[i]) {
				puts("<"); ok = 1;
				break;
			}
		}
		if(!ok) puts("=");
	}
}