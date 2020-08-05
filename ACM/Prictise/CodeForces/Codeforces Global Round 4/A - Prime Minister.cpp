#include <iostream>
#include <algorithm>
using namespace std;

int n,i,j,sum,sumn,a[105],c[105];
bool b[105];
int main()
{
	cin >> n;
	cin >> a[1];
	b[1] = 1;sum += a[1];sumn += a[1];
	for(i = 2;i <= n; i++)
	{
		cin >> a[i];
		if(a[1] >= 2*a[i])
		{
			b[i] = 1;
			sum += a[i];
		}
		sumn += a[i];
	}
	
//	cout << sum << " " << sumn << endl;
	if(sum > sumn/2)
	{
		int t = 0;
		for(i = 1;i <= n; i++)
		{
			if(b[i])
			{
				t++;
				c[++j] = i;
			}
		}
		cout << t << endl;
		for(i = 1;i <= t; i++) cout << c[i] << " ";
	}
	else puts("0");
}