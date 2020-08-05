#include<bits/stdc++.h>
using namespace std;

int n,a,b,c,d,i,sum;
int mon[105];

int main()
{
	cin >> n >> a >> b >> c >> d;
	for(i = 1;i <= n; ++i)
	{
		cin >> mon[i];
		sum += mon[i];
	}
	
	if(b >= d)
	{
		if(sum >= a)
		{
			sum -= b;
			cout << sum << endl;
			return 0;
		}
		
		else if(sum >= c)
		{
			sum -= d;
			cout << sum << endl;
			return 0;
		}
		else 
		{
			cout << sum << endl;
			return 0;
		}
		
	}
	else if(b < d)
	{
		if(sum >= c)
		{
			sum -= d;
			cout << sum << endl;
			return 0;
		}
		
		else if(sum >= a)
		{
			sum -= b;
			cout << sum << endl;
			return 0;
		}
		else 
		{
			cout << sum << endl;
			return 0;
		}
	}
}
