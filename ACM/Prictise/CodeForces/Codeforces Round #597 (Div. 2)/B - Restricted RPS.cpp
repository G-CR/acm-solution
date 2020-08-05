#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c;
char s[105], anss[105];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) anss[i] = '0';
		scanf("%d %d %d", &a, &b, &c);
		scanf("%s", s+1);
		int ans = 0;
		int minr, minp, mins, numr = 0, nump = 0, nums = 0;
		for(int i = 1;i <= n; i++) {
			if(s[i] == 'R') numr++;
			if(s[i] == 'P') nump++;
			if(s[i] == 'S') nums++;
		}
		
		minr = min(a, nums); minp = min(b, numr); mins = min(c, nump);
		ans = minr + minp + mins;
		for(int i = 1;i <= n; i++) {
			if(s[i] == 'R' && b && numr) anss[i] = 'P', b--, numr--; 
			if(s[i] == 'P' && c && nump) anss[i] = 'S', c--, nump--;
			if(s[i] == 'S' && a && nums) anss[i] = 'R', a--, nums--;
		}
		
		for(int i = 1;i <= n; i++) {
			if(anss[i] == '0') {
				if(a) anss[i] = 'R', a--;
				else if(b) anss[i] = 'P', b--;
				else anss[i] = 'S', c--;
			}
		}
		
		if(ceil((float)n/2.0) <= ans) {
			puts("YES");
			for(int i = 1;i <= n; i++) {
				printf("%c", anss[i]);
			}
			puts("");
		}
		else puts("NO");
	}
}