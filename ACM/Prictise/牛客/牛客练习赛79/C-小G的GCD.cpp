#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll f[100];

int main() {
	scanf("%lld", &n);
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= 90; i++) f[i] = f[i-1] + f[i-2];
//	for(int i = 1; i <= 90; i++) {
//		printf("%d %lld\n", i, f[i]);
//	}
	
	__int128 pre = 0;
	for(int i = 1; i <= 90; i++) {
		pre += f[i];
		if(pre >= n) {
			printf("%d\n", i+1);
			break;
		}
	}
}