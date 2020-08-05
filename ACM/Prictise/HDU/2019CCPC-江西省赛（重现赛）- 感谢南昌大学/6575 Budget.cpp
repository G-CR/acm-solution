#include <iostream>
#include <string.h>
using namespace std;

int n,i,sum,x;
string a;

int main()
{
	while(~scanf("%d", &n))
	{
		sum = 0;
		for(i = 1;i <= n; i++)
		{
			cin >> a; getchar();
			x = a[a.length()-1] - '0';
			if(x >= 5) {x = 10-x; sum += x;}
			else sum -= x;
		}
		double ans = (double)sum;
		ans /= 1000;
		printf("%.3lf\n",ans);
	}
	return 0;
}
