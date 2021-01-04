#include <bits/stdc++.h>
using namespace std;

deque <long long> a;
deque <char> f;
vector <long long> resa;
vector <char> resf;
string s;

int main() {
	cin >> s;
	long long now = 0;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			now = now * 10 + (s[i]-'0');
		}
		else {
			f.push_back(s[i]);
			a.push_back(now); now = 0;
		}
	}
	a.push_back(now);
	
	while (!a.empty()) {
		if(f.front() == '^') {
			long long t1 = a.front(); a.pop_front();
			long long t2 = a.front(); a.pop_front();
			t1 ^= t2;
			a.push_front(t1);
			f.pop_front();
		}
		else {
			resa.push_back(a.front()); a.pop_front();
			resf.push_back(f.front()); f.pop_front();
		}
	}
	
	long long ans = resa[0];
	for(int i = 1;i < resa.size(); i++) {
		if(resf[i-1] == '+') ans += resa[i];
		else ans -= resa[i];
	}
	
	printf("%lld\n", ans);
}