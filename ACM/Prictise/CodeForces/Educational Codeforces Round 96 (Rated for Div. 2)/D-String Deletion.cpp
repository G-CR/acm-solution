#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;
vector <int> v;

int main() {
	scanf("%d", &_);
	while(_--) {
		v.clear();
		scanf("%d", &n);
		cin >> s; s += 'a';
		int num = 0;
		for(int i = 0;i < s.length()-1; i++) {
			num++;
			if(s[i] != s[i+1]) {
				v.push_back(num);
				num = 0;
			}
		}
//		for(int i: v) printf("%d ", i); puts("");
		int pos = 0, ans = 0;
		for(int i = 0;i < v.size(); i++) {
			pos = max(pos, i);
			while(v[pos] <= 1 && pos < v.size()) pos++;
			if(pos >= v.size()) {
				ans += (v.size()-i+1)>>1;
				break;
			}
			ans++; v[pos]--;
		}
		printf("%d\n", ans);
	}
}