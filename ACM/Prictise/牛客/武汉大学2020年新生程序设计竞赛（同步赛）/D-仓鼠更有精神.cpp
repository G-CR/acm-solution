#include <bits/stdc++.h>
using namespace std;

int _, k;
string s;
char yy[] = {'a', 'e', 'i', 'o', 'u'};

bool isyy(char a) {
	for(int i = 0;i < 5; i++) {
		if(yy[i] == a) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		scanf("%d", &k);
		for(int i = 0;i < s.length(); i++) {
			if(isyy(s[i])) s[i] = '1';
			else s[i] = '0';
		}
		
		int l = 0, r = 0;
		int ans = s[0]=='1'?1:0, num = s[0]=='0'?1:0;
		while(1) {
			if(r == s.length()-1) {
				while(num > k) {
					if(s[l] == '0')num--;
					l++;
				}
				ans = max(ans, r-l+1);
				break;
			}
			
			if(num <= k) {
				if(num == k) {
					ans = max(ans, r-l+1);
				}
				r++;
				if(s[r] == '0') num++;
			}
			else {
				if(s[l] == '0') num--;
				l++;
			}
		}
		
		printf("%d\n", ans);
	}
}