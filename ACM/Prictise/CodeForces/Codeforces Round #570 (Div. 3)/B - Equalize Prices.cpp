#include <iostream>
using namespace std;

int i, q, n, k, Min = 1e9, Max = 0;
int a[101];

int main() 
{
	cin >> q;
	while(q--)
	{
		cin >> n >> k;
		Min = 1e9, Max = 0;
		for(i = 1;i <= n; i++)
		{
			cin >> a[i];
			if(a[i] > Max) Max = a[i];
			if(a[i] < Min) Min = a[i];
		}
 		if((Min+k) < (Max-k)){puts("-1");continue;}
		cout << Min+k << endl;
	}
}