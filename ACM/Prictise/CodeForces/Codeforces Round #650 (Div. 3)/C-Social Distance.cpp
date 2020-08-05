#include <bits/stdc++.h>
using namespace std;
 
int _, n, k;
string s;
 
int check(int x) {
	for(int i = x+1;i <= x+k; i++) {
		if(i == n) break;
		if(s[i] == '1') return i;
	}
	return -1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		cin >> s;
		int ans = 0, now = 0;
		for(int i = 0;i < n; i++) {
			if(s[i] == '1') now = 0;
			if(s[i] == '0') now++;
			if(now == k+1 || (s[0]=='0'&&i==0)) {
//				cout << "i = " << i << endl;
				int t = check(i);
				if(t == -1) {
					ans++;
				}
				else i = t;
				now = 0;
			}
			
		}
		printf("%d\n", ans);
	}
}

/*
10
5 1
00001
*/