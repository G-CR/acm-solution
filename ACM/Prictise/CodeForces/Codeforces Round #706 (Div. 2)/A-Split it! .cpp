#include <bits/stdc++.h>
using namespace std;

int _;
int n, k;
string s;

bool check(int k) {
	for(int i = 0, j = s.length()-1; i < k; i++, j--) {
		if(s[i] != s[j]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		cin >> s;
		if(k == 0) {puts("YES"); continue;}
		if(k+1 <= (ceil)((double)s.length() / 2) && check(k)) puts("YES");
		else puts("NO");
	}
}