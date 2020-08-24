#include <bits/stdc++.h>
using namespace std;

int _;
string s;
vector <int> num;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		num.clear();
		cin >> s;
		int now = 0;
		for(char i: s) {
			if(i == '0'){
				if(now) num.push_back(now);
				now = 0;
			} 
			else now++;
		}
		if(now) num.push_back(now);
		
		sort(num.begin(), num.end(), cmp);
		
		int ans = 0;
		for(int i = 0;i < num.size(); i += 2) {
			ans += num[i];
		}
		
		printf("%d\n", ans);
	}
}