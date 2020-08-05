#include <iostream>
using namespace std;

long long q, k, n, a, b, t;

int main()
{
	cin >> q;
	while(q--)
	{
		cin >> k >> n >> a >> b;
		if(k - n*a > 0) cout << n << endl;
		else if(k - n*b <= 0) puts("-1");
		else 
		{
			int t = (n*a - k) / (a-b);
			cout << n-t-1 << endl;
		}		
	}
}