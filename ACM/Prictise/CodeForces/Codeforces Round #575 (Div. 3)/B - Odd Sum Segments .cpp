#include <iostream>
using namespace std;
const int N = 2e5+10;
int q,k,n,i,j,odd;
long long a[N],sum,sheng;
bool ok[N];

int main()
{
	cin >> q;
	while(q--)
	{
		cin >> n >> k;
		for(j = 1;j <= n; j++) ok[j] = 0;
		odd = 0;
		
		for(i = 1;i <= n; i++)
		{
			cin >> a[i];
			if(a[i]%2) odd++;
		}

		if(odd < k) {puts("NO"); continue;}
		
		sum = 0;
		for(i = 1;sum <= k-2; i++)
		{
			if(a[i]%2) 
			{
				sum++;
				ok[i] = 1;
			}	
		}
		sheng = 0;
		for(j = i;j <= n; j++)
		{
			sheng += a[j];
		}
			
		if(!(sheng%2)) {puts("NO"); continue;}
		
		ok[n] = 1;
		puts("YES");
		for(i = 1;i <= n; i++)
			if(ok[i]) cout << i << " ";
		cout << endl;
	}
}