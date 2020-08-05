#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	
	int i = n-1, j = m-1;
	int ans;
	while(i >= 0 && j >= 0) {
		if(s[i] == t[j]) {
			if(i-1<0 || j-1<0) {
				ans = i+j;
				break;
			}
			i--;
			j--;
		}
		else {
			ans = i+j+2;
			break;
		}
	}
	printf("%d\n", ans);
}