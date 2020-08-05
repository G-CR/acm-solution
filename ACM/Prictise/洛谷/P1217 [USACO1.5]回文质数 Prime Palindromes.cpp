#include <bits/stdc++.h>
using namespace std;

const int m = 10000000;
bool a[m];
vector <int> vc;
int l, r;

void solve() {
	for(int i = 1;i <= m; i++) a[i] = 1;
	for(int i = 3;i <= m; i++) if(!(i%2)) a[i] = 0;
	for(int i = 2;i <= m; i++) {
		if(a[i]) {
			for(int j = i*2; j<= m; j += i)
				a[j] = 0;
		}
	}
	
//	for(int i = 2;i <= m; i++)
//		if(a[i]) cout << i << " ";
}


int main() {
	solve();
	for(int i = 3;i <= m; i += 2) {
		if(a[i]) {
			int t = i;
			string s1 = "", s2 = "";
			while(t) {
				s1 += (t%10)+'0';
				t /= 10;
			}
			s2 = s1;
			reverse(s1.begin(), s1.end());
			if(s1 == s2) {
				t = 0;
				for(int i = 0;i < s1.length(); i++) {
					t *= 10;
					t += s1[i]-'0';
				}
				vc.push_back(t);
			}
		}
	}
	
	scanf("%d %d", &l, &r);
	if(l <= 2) puts("2");
	for(int i = 0;i < vc.size(); i++) {
		if(l <= vc[i] && vc[i] <= r) printf("%d\n", vc[i]);
	}
}