#include <bits/stdc++.h>
using namespace std;

int _, n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		int t = n % 3;
		int num = n / 3;
		while(num--) cout << "abc";
		if(t == 1) cout << 'a';
		else if(t == 2) cout << "ab";
		puts("");
	}
}