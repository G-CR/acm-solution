#include <bits/stdc++.h>
#define ll long long
using namespace std;

int q;
ll n, k;
char s[1000006];

int main() {
	scanf("%d", &q);
	while(q--) {
		ll pos = 1;
		scanf("%lld %lld", &n, &k);
		scanf("%s", s+1);
		for(int i = 1;i <= n; i++) {
			if(k <= 0) break;
			if(s[i] == '0') {
				while(s[pos] == '0') pos++;
				if(pos >= i) continue;
				swap(s[i], s[max(pos++, i-k)]);
				k -= (i-pos+1);
			}
		}
		for(int i = 1;i <= n; i++) printf("%c", s[i]);
		puts("");
	}
}