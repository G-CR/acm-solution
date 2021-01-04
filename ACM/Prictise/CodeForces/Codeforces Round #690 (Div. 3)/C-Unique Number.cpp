#include <bits/stdc++.h>
using namespace std;

int _, x;
vector<int> ans;

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		scanf("%d", &x);
		if(x > 45) {
			puts("-1");
			continue;
		}
		int sum = 0;
		for(int i = 9;i >= 1; i--) {
			if(sum == x) break;
			if(x-sum < i) continue;
			sum += i;
			ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		for(int i: ans) printf("%d", i); puts("");
	}
}