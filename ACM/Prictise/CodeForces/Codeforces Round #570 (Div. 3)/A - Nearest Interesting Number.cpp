#include<bits/stdc++.h>
using namespace std;
int a, sum, t;
int main()
{
	cin >> a;
	while(1)
	{
		t = a++, sum = 0;
		while(t > 0)
		{
			sum += t%10;
			t /= 10;
		}
		if(!(sum % 4)) break;
	}
	cout << a-1 << endl;
}