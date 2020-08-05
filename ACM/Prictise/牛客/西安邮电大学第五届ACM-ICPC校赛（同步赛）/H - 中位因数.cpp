#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
long long f[1000006], g[1000006];
bool ok[1000006];
int mx[1000006], _;

int main() {
	for(int i = 1;i*i <= 1000000; i++) {
		int x = i*i;
		f[x] = i; ok[x] = 1;
	}
	
	for(int i = 1;i <= 1000000; i++) {
		for(int j = i;j <= 1000000; j += i) {
			if(ok[j]) continue;
			int x = i; int y = j/i;
			if(x > y) swap(x, y);
			if(mx[j] < x) {
				f[j] = (x+y)/2;
				mx[j] = x;
			}
		}
	}
	
	for(int i = 1;i <= 1000000; i++) g[i] = (g[i-1] + f[i]) % mod;
	
	scanf("%d", &_);
	while(_--) {
		int x; 
		scanf("%d", &x);
		printf("%lld\n", g[x]);
	}
}