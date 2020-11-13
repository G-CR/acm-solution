#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s;

int main() {
	while(getline(cin, s) && s != "#") {
		int ans = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == ' ') continue;
//			printf("%d*%d\n", s[i]-'A'+1, i);
			ans += (s[i]-'A'+1)*(i+1);
		}
		printf("%d\n", ans);
	}
}