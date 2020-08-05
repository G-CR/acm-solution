#include <iostream>

using namespace std;
const int N = 100000000;
bool a[N];
int i,j,n;

void solve()
{
	cin >> n;
	for(i = 1;i <= n; i++) a[i] = 1;
	for(i = 3;i <= n; i++) if(!(i%2)) a[i] = 0;
	for(i = 2;i <= n; i++)
	{
		if(a[i])
		{
			for(j = i*2; j<= n; j += i)
				a[j] = 0;
		}
	}
	for(i = 2;i <= n; i++)
		if(a[i]) cout << i << " ";
}

int main()
{
	solve();
}