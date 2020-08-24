#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int t = (ceil)((double)n/4);
		n -= t;
		for(int i = 1;i <= n; i++) printf("9");
		for(int i = 1;i <= t; i++) printf("8");
		puts("");
	}
}