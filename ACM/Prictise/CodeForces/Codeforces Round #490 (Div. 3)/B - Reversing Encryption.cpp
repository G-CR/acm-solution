#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set <int> st;
vector <int> vc;

int main() {
	scanf("%d", &n);
	cin >> s;
	for(int i = 2;i <= n-1; i++) {
		if(n%i == 0) {
			vc.push_back(i);
		}
	}
	sort(vc.begin(), vc.end());
	
	for(int i = 0;i < vc.size(); i++) {
		string t = "";
		for(int j = vc[i]-1;j >= 0; j--) {
			t += s[j];
		}
		for(int j = vc[i];j < n; j++) {
			t += s[j];
		}
		s = t;
	}
	
	for(int i = n-1;i >= 0; i--) printf("%c", s[i]);
	puts("");
}