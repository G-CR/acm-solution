#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> ans;

int main() {
	scanf("%d %d", &n, &m);
	int cha, tot;
	if(n >= m) {
		cha = n - m + 1;
		n -= cha; m--;
		for(int i = 1; i <= cha; i++) ans.push_back(i);
		tot = (1 + cha) * cha / 2;
		ans.push_back(-tot);
	}
	else {
		cha = m - n + 1;
		n--; m -= cha;
		for(int i = 1; i <= cha; i++) ans.push_back(-i);
		tot = (1 + cha) * cha / 2;
		ans.push_back(tot);
	}
	
	for(int i = 1; i <= n; i++) {
		ans.push_back(++tot);
		ans.push_back(-tot);
	}
	
	for(int i: ans) printf("%d ", i);
}