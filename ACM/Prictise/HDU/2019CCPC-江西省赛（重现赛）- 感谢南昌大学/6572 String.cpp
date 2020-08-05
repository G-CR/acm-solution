#include <iostream>
#include <cstring>
using namespace std;

long long n,i,ans1,ans2;
string s;
long long num[5];
bool ok = 1;

long long measure(long long x, long long y)
{	
	long long z = y;
	while(x % y != 0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}

int main()
{
	while(~scanf("%lld", &n))
	{
		ok = 1;
		for(i = 1;i <= 4; i++) num[i] = 0;
		cin >> s;
		for(i = 0;i < n; i++)
		{
			if(s[i] == 'a') num[1]++;
			else if(s[i] == 'v') num[2]++;
			else if(s[i] == 'i') num[3]++;
			else if(s[i] == 'n')num[4]++;
		}
		
	for(i = 1;i <= 4; i++) 
		if(num[i] == 0) 
			{ok = 0;puts("0/1");break;}
		if(!ok) continue;
		
		ans2 = n*n*n*n;
		ans1 = num[1]*num[2]*num[3]*num[4];
		long long t = measure(ans2, ans1);
		ans1 /= t,ans2 /= t;
		cout << ans1 << "/" << ans2 << endl;
	}
	return 0;
}