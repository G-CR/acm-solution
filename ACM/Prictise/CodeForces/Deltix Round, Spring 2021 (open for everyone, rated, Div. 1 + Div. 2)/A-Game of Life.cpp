#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
char s[N];
queue <int> q;
bool vis[N];

int main() {
	int _; scanf("%d", &_); while(_--) {
		int n, m; scanf("%d %d", &n, &m);
		scanf("%s", (s+1));
		s[n+1] = '0'; s[0] = '0';
		while(m--) {
			int res = 0;
			for(int i = 1; i <= n; i++) {
				if(s[i] == '0') {
					int num = (s[i-1] == '1') + (s[i+1] == '1');
					if(num == 1) {
						vis[i] = 1;
						res++;
					}
				}
			}
			
			if(!res) break;
			
			for(int i = 1; i <= n; i++) {
				if(vis[i] == 1) {
					s[i] = '1';
					vis[i] = 0;
				}
			}
		}
		
		for(int i = 1; i <= n; i++) {
			printf("%c", s[i]);
		} puts("");
	}
}