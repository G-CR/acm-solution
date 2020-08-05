#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
struct mat{
	ll m[105][105];
};
ll k,n;
mat a,e;
mat mul(mat x, mat y)
{
	mat t;
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= n; j++)
			t.m[i][j] = 0;
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= n; j++)
			for(int k = 1;k <= n; k++)
				t.m[i][j] = t.m[i][j] % mod + x.m[i][k] * y.m[k][j] % mod;
	return t;
}

mat pow(mat x, ll y)
{
	mat ans = e;
	while(y)
	{
		if(y & 1) ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}


int main() 
{
	cin >> n >> k;
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= n; j++)
			cin >> a.m[i][j];
			
	for(int i = 1;i <= n; i++) e.m[i][i] = 1;					
	mat ans = pow(a,k);
	
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= n; j++)
			{
				cout << ans.m[i][j] % mod << " ";
			}
			cout << endl;
	}
			
}