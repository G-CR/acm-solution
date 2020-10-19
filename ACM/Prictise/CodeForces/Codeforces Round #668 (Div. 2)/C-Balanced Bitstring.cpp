#include<bits/stdc++.h>
using namespace std;

int n, k;
char s[300005];

void check(bool f) {
	if (f) puts("NO");
	else {
		int res = 0, an = 0;
		for (int i = 1; i <= k; i++) {
			if (s[i] == '1') res++;
			else if (s[i] == '?') an++;
		}
		if (res > (k / 2)) {
			puts("NO");
		} else if (res + an >= k / 2) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		scanf("%d %d %s", &n, &k, s+1);
		bool f = 0;
		for (int i = 1; i <= k; i++) {
			int ok = 0; 
			char c = 'q';
			for (int j = i; j <= n; j += k) {
				if (s[j] == '1') {
					if (c == 'q') c = '1';
					else if (c == '0') {
						ok = 1;
						break;
					}
				} else if (s[j] == '0') {
					if (c == 'q') c = '0';
					else if (c == '1') {
						ok = 1;
						break;
					}
				}
			}
			if (ok == 1) {
				f = 1;
				break;
			}
			if (c != 'q') {
				s[i] = c;
			}
		}
			
		check(f);
	}
}