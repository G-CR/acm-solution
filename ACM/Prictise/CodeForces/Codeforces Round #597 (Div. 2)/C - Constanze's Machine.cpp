#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long ans[100005], fib[100005];
char s[100005];
int n;

void calc() {
	fib[2] = 2; fib[3] = 3;
	for(int i = 4;i <= 100000; i++) {
		fib[i] = (fib[i-1] + fib[i-2]) % mod;
	}
}

long long find(int k) {
	long long num = 1;
	for(int i = k+1;i <= n; i++) {
		if(s[i] != s[i-1]) return num;
		num++;
	}
	return num;
}

int main() {
	calc();
	scanf("%s", s+1);
	n = strlen(s+1);
	bool ok = 1;
	long long anss = 1, cnt = 0, num;
	for(int i = 1;i <= n; i++) {
		if(s[i] == 'w' || s[i] == 'm') {
			ok = 0; break;
		}
		if(s[i] == 'u' || s[i] == 'n') {
			num = find(i);
			if(num != 1) {
				i += (num-1);
				num = fib[num];
				ans[++cnt] = num % mod;
			}
		}
	}
	
	for(int i = 1;i <= cnt; i++) {
		anss = anss * (ans[i]%mod) % mod;
	}
	
	if(!ok) puts("0");
	else {
		printf("%lld\n", anss);
	}
}