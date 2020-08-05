#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k;
vector <long long> res;

void find(long long x) {
	for(int i = 1;i*i <= x; i++) {
		if(x%i == 0) {
			res.push_back(i);
			res.push_back(x/i);
		} 
	}
}

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		res.clear();
		scanf("%lld %lld", &n, &k);
		find(n);
		sort(res.begin(), res.end(), cmp);
		int num = res.size();
		for(int i = 0;i < num; i++) {
			if(k >= res[i]) {
				printf("%lld\n", n/res[i]);
				break;
			}
		}
	}
}