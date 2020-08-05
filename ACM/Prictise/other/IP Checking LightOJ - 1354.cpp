#include <bits/stdc++.h>
using namespace std;

stack <int > sta;
int _;
string a, b;
vector <int> chea, cheb;

int change(string s) {
	int n = s.length();
	int start = n;
	for(int i = 0;i < n; i++) {
		if(s[i] != 0) {
			start = i;
			break;
		}
	}
	for(int i = start; i < n; i++) sta.push(s[i]-'0');
	int t = 1, res = 0;
	while(!sta.empty()) {
		int k = sta.top(); sta.pop();
		res += (t*k); t *= 2;
	}
	return res;
}

bool check() {
	for(int i = 0;i < 4; i++) {
		if(chea[i] != cheb[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		chea.clear(); cheb.clear();
		cin >> a >> b;
		int p = 0;
		for(int i = 0;i < a.length(); i++) {
			if(a[i] != '.') {
				p *= 10;
				p += (a[i]-'0');
			}
			else {
				chea.push_back(p);
				p = 0;
			} 
		}
		chea.push_back(p);
		
		p = 4;
		int head = 0;
		while(p--) {
			string q = b.substr(head, 8);
			cheb.push_back(change(q));
			head += 9;
		}
		printf("Case %d: %s\n", ++cas, check()?"Yes":"No");
	}
}