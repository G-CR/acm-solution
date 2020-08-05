#include <bits/stdc++.h>
using namespace std;

long long num[30];
map <int, long long> error;
char s[200005];
int t, n, m, x;

int main() {
	scanf("%d", &t);
	while(t--) {
		error.clear();
		for(int i = 1;i <= 26; i++) num[i] = 0;
		
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) 
			scanf(" %c", &s[i]);
		for(int i = 1;i <= m; i++) {
			scanf("%d", &x);
			error[x]++;
		}
		
		int p = 1;
		for(int i = n;i >= 1; i--) {
			if(error[i]) p += error[i];
			num[s[i]-'a'+1] += p;
		}
		
		for(int i = 1;i <= 26; i++) printf("%lld ", num[i]);
		puts("");
	}
}