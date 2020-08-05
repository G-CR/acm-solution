#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n;
char s[100005];
bool sta;

int main() {
	scanf("%d", &n);
	bool sta = 0;
	long long pre = 0, ans = 0, num = 0;
	for(int i = 1;i <= n; i++) {
		scanf(" %c", &s[i]);
		if(!sta && s[i] == '1') {
			sta = 1;
			pre += i;
			num++;
		}
		else if(sta && s[i] == '1') {
			ans = (ans + (i*num-pre) % mod) % mod;
			pre += i;
			num++;
		}
//		printf("pre = %d ans = %d num = %d\n", pre, ans, num);
	}
	printf("%lld\n", ans);
}