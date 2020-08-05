#include <iostream>
using namespace std;

int w,h,i;
long long sum = 4;

int main()
{
	cin >> w >> h;
	for(i = 1;i <= w-1; i++)
		sum = sum * 2 % 998244353;
	for(i = 1;i <= h-1; i++)
		sum = sum * 2 % 998244353;
	cout << sum << endl;
}