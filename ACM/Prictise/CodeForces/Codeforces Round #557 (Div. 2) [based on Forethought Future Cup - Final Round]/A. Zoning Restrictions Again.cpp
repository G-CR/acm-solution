#include<iostream>
using namespace std;

int house[55];
int n,h,m,li,ri,xi,sum;

int main()
{
	cin >> n >> h >> m;
	for(int i = 1;i <= n; ++i)
		house[i] = h;
	while(m--)
	{
		cin >> li >> ri >> xi;
		for(int i = li;i <= ri; ++i)
		{
			if(house[i] > xi)
				house[i] = xi;
		}
	}
	
	for(int i = 1;i <= n; ++i)
		sum += house[i]*house[i];
	cout << sum;
}
