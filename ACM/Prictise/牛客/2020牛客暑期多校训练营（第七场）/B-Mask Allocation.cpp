#include <bits/stdc++.h>
using namespace std;

int _, n, m, sum;
vector <int> ans;

void fuck_gcd(int a, int b) {
	if(sum == 0) return;
	if(a > b) swap(a, b);
	for(int i = 0;i < a; i++) ans.push_back(a);
	sum -= a*a;
	fuck_gcd(b-a, a);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		scanf("%d %d", &n, &m);
		sum = n*m;
		fuck_gcd(n, m);
		int cnt = ans.size();
		printf("%d\n", cnt);
		for(int i = 0;i < cnt; i++) printf("%d ", ans[i]);
		puts("");
	}
}