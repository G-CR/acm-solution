//https://ac.nowcoder.com/acm/contest/893/B
#include<iostream>
using namespace std;


int main()
{
	int T,n,count;
	cin >> T;
	while(T--)
	{
		cin >> n;
		count = 0;
		while(n > 1)
		{
			if(n % 10 == 0)
			{
				n /= 10;
				count++;
			}
			else
			{
				n++;
				count++;
			}
		}
		cout << count << endl;
	}
}
