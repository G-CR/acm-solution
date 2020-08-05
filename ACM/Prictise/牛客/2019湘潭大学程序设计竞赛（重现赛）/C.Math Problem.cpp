//https://ac.nowcoder.com/acm/contest/893/C
#include<iostream>
#define ll long long
using namespace std;

ll sst(ll n)
{
	if(n == 0)
		return 0;
	ll sum = 0;
	ll m = (n - 1) / 192;
	
	sum = (1 + m) * m / 2 * 192;
	return sum + 1 + m;
}


int main()
{
	int T;
	ll L, R;
	cin >> T;
	while(T--)
	{
		cin >> L >> R;
		cout << sst(R) - sst(L - 1) << endl;
	}
}
