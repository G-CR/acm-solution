#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2*1e5+10;

int candy[N],sum,i,q,n,t;
bool num[N];

int main() 
{
	cin >> q;
	while(q--)
	{
		sum = 0;
		cin >> n;
		
		for(i = 1;i <= n; i++) candy[i] = 0,num[i] = 0;
		for(i = 1;i <= n; i++){ cin >> t; candy[t]++; }
		
		sort(candy+1,candy+1+n);
		
		for(i = n;i >= 1; i--)
		{
			if(!num[candy[i]])
			{
				num[candy[i]] = 1;
				sum += candy[i];
			}
			else
			{
				if(candy[i]-1 >= 0)
				{
					candy[i]--;
					i++;
				}		
			}
			
		}
		
		cout << sum << endl;
	}
}