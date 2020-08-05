#include<iostream>
using namespace std;

long long m,n,i;
long long a[100001],b[100001];
long long jn,on,jm,om;

int main()
{
	cin >> n >> m;
	for(i = 0;i < n; i++)
	{
		cin >> a[i];
		if(a[i] % 2 == 0)
			on++;
		else
			jn++;
	}
		
	for(i = 0;i <m; i++)	
	{
		cin >> b[i];
		if(b[i] % 2 == 0)
			om++;
		else
			jm++;
	}
	long long sum = min(on,jm) + min(jn,om);
	cout << sum;
	
}
