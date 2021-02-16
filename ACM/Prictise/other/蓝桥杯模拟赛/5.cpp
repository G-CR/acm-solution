#include <bits/stdc++.h>
using namespace std;

string s = "LANQIAO";

int main() {
	int n = s.length();
	int ans = 0;
	for(int i = 0;i < n; i++) {
		for(int j = i+1;j < n; j++) {
			ans += abs(s[i]-s[j]);
		}
	}
	
	printf("%d\n", ans);
}