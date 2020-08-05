#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int T;
ll n;
char s[15],mb[15];

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%lld", &n);
		printf("Case %d: ", p);
		int cnt = 0;
		while(n > 0) {
			mb[++cnt] = (n % 10)+'0';
			n /= 10;
		}
		
		int num = 2*cnt-1;
		int t = 0;
		for(int i = 1;i <= (num/2)+1; i++) {
			s[i] = s[num-t] = mb[cnt];
			cnt--; t++;
		}
		
		for(int i = 1;i <= num; i++) printf("%c", s[i]);
		puts("");
	}
}