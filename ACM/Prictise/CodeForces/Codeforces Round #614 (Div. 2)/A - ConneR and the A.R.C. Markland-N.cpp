#include <bits/stdc++.h>
using namespace std;

int t, n, s, k, x;
map <int, bool> close;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &s, &k);
		int top, bot;
		top = bot = s;
		close.clear();
		for(int i = 1;i <= k; i++) {
			scanf("%d", &x);
			close[x] = 1;
			while(close[top]) top++;
			while(close[bot]) bot--;
		}
		
		if(top-s <= s-bot) {
			if(top <= n) printf("%d\n", top-s);
			else printf("%d\n", s-bot);
		}
		else {
			if(bot > 0) printf("%d\n", s-bot);
			else printf("%d\n", top-s);
		}
	}
}