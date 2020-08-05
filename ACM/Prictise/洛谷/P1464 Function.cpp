#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll res[25][25][25];

ll fun(ll a, ll b, ll c) {
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(res[a][b][c] != 0) return res[a][b][c];
	else if(a > 20 || b > 20 || c > 20) return res[a][b][c] =  fun(20, 20, 20);
	else if(a < b && b < c) return res[a][b][c] =  fun(a,b,c-1)+fun(a,b-1,c-1)-fun(a,b-1,c);
	return res[a][b][c] = fun(a-1,b,c)+fun(a-1,b-1,c)+fun(a-1,b,c-1)-fun(a-1,b-1,c-1);
}

int main() {
	ll a, b, c;
	while(1) {
		memset(res,0,sizeof(res));
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a == -1&&b == -1&&c == -1) break;
		ll o = a, p = b, q = c;
		if(a > 20) a = 21;
		if(b > 20) b = 21;
		if(c > 20) c = 21;
		printf("w(%lld, %lld, %lld) = %lld\n", o, p, q, fun(a,b,c));
		
	}
}