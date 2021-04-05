#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int _, n, v, num, sum, ans;
vector <int> a, s, t;

int getcha() {
	int cha = 0;
	for(int i = 0; i < t.size(); i++) cha += t[i];
	return abs(sum - cha - cha);
}
void sa() {
	double T = 10000, D = 0.99;
	int cur = getcha();
	while(T > 1e-4) {
		int pos1 = rand() % s.size();
		int pos2 = rand() % t.size();
		swap(s[pos1], t[pos2]);
		int now = getcha();
		if(now < cur) {
			cur = now;
			if(ans > cur) ans = cur;
		}
		else if(exp(-abs(now-cur)/T) > rand()) {
			cur = now;
		}
		else swap(s[pos1], t[pos2]);
		T *= D;
	}
}

void solve() {
	int num = 100;
	while(num--) {
		sa();
	}
}

int main() {
	srand(time(NULL));
	while (~scanf("%d", &n) && n > 0) {
		s.clear(); t.clear(); a.clear();
		sum = 0; ans = 1e9;
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &v, &num);
			sum += v * num;
			while (num--) {
				a.push_back(v);
			}
		}
		sort(a.begin(), a.end());
		
		int now = 0;
		for(int i = 0; i < a.size(); i++) {
			now += a[i];
			if(now <= sum / 2) s.push_back(a[i]);
			else t.push_back(a[i]);
		}
		
		if(s.empty()) {
			printf("%d 0\n", t[0]);
			continue;
		}
		else if(t.empty()) {
			printf("%d 0\n", s[0]);
			continue;
		}
		
		solve();
		
		int res = 0;
		for(int i = 0; i < s.size(); i++) {
			res += s[i];
		}
		
		printf("%d %d\n", max(res, sum-res), min(res, sum-res));
	}
}