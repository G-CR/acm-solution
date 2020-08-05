//https://ac.nowcoder.com/acm/contest/893/E
#include<iostream>
#define ll long long
using namespace std;

int a[10000005];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll Min = 0,Max = 0,Li = 0,m,n,i;
		cin >> n >> m;
		int flag = 0;
		for(i = 1;i <= n; ++i)
		{
			cin >> a[i];
			if(a[i] > Li)
				Li = a[i];
		}
		
//		cout << "Li = " << Li << endl;
		
		for(i = 1; ; ++i)
		{
			if(a[i] == Li)
			{
				if(Min <= m && m <= Max)
				{
					cout << "YES" << endl;
					flag = 1;
				}
				
				else if(m - Max - Li <= 0)
				{
					cout << "YES" << endl;
					flag = 1;
				}
				
				else
				{
					Max += Li;
					Min += Li;
//					cout << "Min = " << Min << " " << "Max = " << Max << endl;
					continue;
					
				}
				
			}
			
			if(m <= Min)
			{
				cout << "NO" << endl;
				flag = 1;
			}
			
			if(flag == 1)
				break;
				
			Min++;
			
			if(i > n)
				i = 1;
				
			Max += a[i];
			
//			cout << "Min = " << Min << " " << "Max = " << Max << endl;
		}
			
	}
}
