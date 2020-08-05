//https://acm.ecnu.edu.cn/contest/231/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, k, x;
char s[500005], sam[30],pp[500005][30];


int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &k, &x);
	scanf("%s", s+1);
	int len = strlen(s+1);
	for(int i = 1;i <= m; i++) {
		scanf("%s", sam+1);
		int cnt = strlen(sam+1);
		sort(sam+1,sam+1+cnt);
		for(int j = 1;j <= cnt; j++) pp[i][j] = sam[j];
	}
	
	
	int cnt = 1,j = 1;
	for(int i = 1;i <= len; i++) {
		if(s[i] == '#') {
			ll t1 = x % (ll)pow(k,m-cnt);
			if(t1 != 0) t1 = 1;
			
			ll t2 = x / (ll)pow(k,m-cnt++)+t1;
			t2 %= k; 
			if(t2 == 0) printf("%c", pp[j++][k]);
			else printf("%c", pp[j++][t2]);
		}
		else {
			printf("%c", s[i]);
		}
	}
}