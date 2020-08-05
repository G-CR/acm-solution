#include<iostream>
using namespace std;

long long sum[20],n,N;

int main()
{
	for(int i = 1;i <= 20; i++)
		sum[i] = 1;
		
	for(int i = 1;i <= 15; ++i)
	{
		for(int j = 1;j <= i; ++j)
		{
			sum[i] *= i;
		}
//		cout <<"sum[" << i << "] = " <<sum[i] << endl;
	}
	while(~scanf("%lld",&n))
	{
		
		for(int i = 1;i <= 16;i++)
		{
			if(i==16)
				cout << "15" << endl;
				
			if(n == 1)
			{
				cout << "1" << endl;
				break;
			}
			if(n >= sum[i])
				continue;
			else
			{
				cout << i - 1 << endl;
				break;
			}
			
		}
	}
	
}
