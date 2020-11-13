//https://ac.nowcoder.com/acm/contest/7697#question
#include <bits/stdc++.h>
using namespace std;
  
string s;
  
int check(int si, int sj) {
	int ti = si, tj = sj;
	while(s[ti] == s[tj] && tj < s.length()) {
//      printf("tj = %d\n", tj);
		ti++; tj++;
	}
	return tj-si;
}
  
int main() {
   cin >> s;
   int ans = 0;
	for(int j = 1;j < s.length(); j++) {
		if(s[0] == s[j]) {
			int now = check(0, j);
//          printf("j = %d, now = %d\n", j, now);
//          if(now < s.length()) {
//              ans = max(ans, now);
//          }
			ans = max(ans, check(0,j));
		} 
	}
   printf("%d\n", ans);
}