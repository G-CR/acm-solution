#include <bits/stdc++.h>
using namespace std;

int _, n;
vector <int> res;

int main() {
	scanf("%d", &_);
	while(_--) {
		res.clear();
		scanf("%d", &n);
		int t = 1;
		while(n) {
			int k = n%10; n /= 10;
			k *= t;
			if(k) res.push_back(k);
			t *= 10;
		}
		printf("%d\n", (int)res.size());
		for(int i = 0;i < res.size(); i++) {
			printf("%d ", res[i]);
		}
		puts("");
	}
}