#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m;
vector <int> res;
int cal(long long num) {
	int ans = 1;
	long long mi = 1;
	while(1) {
		mi *= 2;
		if(mi > num) break;
		ans++;
	}
	return ans;
}

int main() {
	int num;
	scanf("%d", &num);
	for(int i = 1;i <= num; i++) {
		scanf("%lld %lld", &n, &m);
		if(m >= cal(n)) res.push_back(i);
		else res.push_back(i-1);
	}
	
	long long ans = res[0];
	for(int i = 1;i < res.size(); i++) {
		ans ^= res[i];
	}
	
	printf("%lld\n", ans);
}