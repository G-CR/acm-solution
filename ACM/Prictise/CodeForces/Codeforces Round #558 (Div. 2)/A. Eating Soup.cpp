#include<iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> n >> m;
	if(m == 0)
	{
		cout << "1" << endl;
		return 0;
	}
	else if(m == n)
	{
		cout << "0" << endl;
		return 0;
	}
	
	if(n <= 2*m)
		cout << n - m << endl;
	else
		cout << m << endl;
		
}
