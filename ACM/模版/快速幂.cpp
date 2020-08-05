#include <bits/stdc++.h>
using namespace std;


long long poww(long long  a,long long b)
{
	long long ans = 1,base = a;
	while(b)
	{
		if(b&1)
			ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	cout << poww(a,b) << endl;
}