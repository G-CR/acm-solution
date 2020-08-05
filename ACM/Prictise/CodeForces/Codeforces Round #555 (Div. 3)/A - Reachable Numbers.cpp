#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll a,count,flag;

int main()
{
	cin >> a;
	count++;
	
	while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7&&a!=8&&a!=9)
	{
		a++;
		if(a % 10 == 0)
		{
			while(a % 10 == 0)
				a /= 10;
		}
		
			
//		cout << a << endl;
		count++;
	}
	cout << count + 8;
}
