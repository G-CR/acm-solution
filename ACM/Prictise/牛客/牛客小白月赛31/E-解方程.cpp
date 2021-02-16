#include <bits/stdc++.h>
using namespace std;

int _;
int a, b;
map <int, int> num;

void solve(int k) {
	for(int i = 2;i*i <= k; i++) {
		while(k%i == 0) {
			k /= i;
			num[i]++;
		}
		
	}
	if(k != 1) num[k]++;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		num.clear();
		scanf("%d %d", &a, &b);
		solve(a); solve(b);
		int ans = 1;
		for(auto i: num) {
			ans *= (i.second+1);
		}
		printf("%d\n", ans);
	}	
}