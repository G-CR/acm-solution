#include<iostream>
using namespace std;
const long long mod = 199999;
long long sum[200005], ans[200005];
string s;
int _;

int main() {
	long long cnt = 1;
	sum[1] = 1;
	for(long long i = 2;i < mod; i++) {
		cnt += i;
		sum[i] = ((sum[i-1]%mod) + ((cnt*i)%mod))%mod;
	}
	
	ans[1] = 1;
	for(long long i = 2;i < mod; i++) {
		ans[i] = ((ans[i-1]%mod) * ((sum[i]*i)%mod))%mod;
	}
	
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		long long num = 0;
		for(int i = 0;i < min((int)s.length(), 8); i++) {
			num *= 10;
			num += s[i]-'0';
		}
		if(num >= mod) puts("0");
		else {
			printf("%lld\n", (ans[num]+mod)%mod);
		}
	}		
}