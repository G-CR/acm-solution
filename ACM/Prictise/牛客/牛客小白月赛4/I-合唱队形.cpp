#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector <int> num;

int main() {
	scanf("%d", &n);
	cin >> s;
	int l = 0, r = 0;
	while(l < (int)s.length()) {
		r = l-1;
		if(s[l] == '0') {
			while(r+1 < s.length() && s[r+1] == '0') r++;
			num.push_back(r-l+1);
		}
		
		if(s[l] == '1') {
			while(r+1 < s.length() && s[r+1] == '1') r++;
			num.push_back(-(r-l+1));
		}
		l = r+1;
	}
	
	int ma = 0, girl = 0;
	for(int i: num) {
		ma = max(ma, i);
		if(i > 0) girl++;
	}
	
	if(girl > 1) ma++;
	for(int i = 0;i < num.size(); i++) {
		if(i > 0 && i < num.size()-1 && num[i] == -1 && girl > 2) {
			ma = max(ma, num[i-1]+num[i+1]+1);
		}
	}
	
	printf("%d\n", ma);
}