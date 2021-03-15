#include <bits/stdc++.h>
using namespace std;

int _;
int h, m;
string s;

bool ok[] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
map <int, int> mp;
int a, b, c, d;

void init() {
	mp[1] = 1;
	mp[2] = 5;
	mp[5] = 2;
	mp[8] = 8;
	mp[0] = 0;
}

vector <int> check(int t) {
	vector <int> res;
	int now1 = a*10+b, now2 = c*10+d;
	
	now2 += t;
	int num = now2 / m;
	now2 %= m;
	now1 += num;
	now1 %= h;
	
	int ta, tb, tc, td;
	ta = now1 / 10; tb = now1 % 10;
	tc = now2 / 10; td = now2 % 10;
	
	if(ok[ta] && ok[tb] && ok[tc] && ok[td] && mp[td]*10+mp[tc] < h && mp[tb]*10+mp[ta] < m) {
		res.push_back(ta);
		res.push_back(tb);
		res.push_back(tc);
		res.push_back(td);
	}
	
	return res;
}

int main() {
	init();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &h, &m);
		cin >> s;
		
		a = s[0]-'0', b = s[1]-'0', c = s[3]-'0', d = s[4]-'0';
		
		int t = 0;
		vector <int> ans;
		while(1) {
			ans = check(t);
			if(!ans.empty()) break;
			t++;
		}
		
		printf("%d%d:%d%d\n", ans[0], ans[1], ans[2], ans[3]);
	}
}