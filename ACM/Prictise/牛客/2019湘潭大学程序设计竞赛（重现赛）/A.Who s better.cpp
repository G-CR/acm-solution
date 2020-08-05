//https://ac.nowcoder.com/acm/contest/893/A
#include<iostream>
using namespace std;

int n1,n2,p1,p2,s1,s2;

int main()
{
	cin >> n1 >> p1 >> s1;
	cin >> n2 >> p2 >> s2;
	
	if(n1 > n2)
	{
		cout << "1";
		return 0;
	}
	else if(n1 < n2)
	{
		cout << "2";
		return 0;
	}
	else
	{
		if(p1 < p2)
		{
			cout << "1";
			return 0;
		}
		else if(p1 > p2)
		{
			cout << "2";
			return 0;
		}
		else 
		{
			if(s1 < s2)
			{
				cout << "1";
				return 0;
			}
			else if(s1 > s2)
			{
				cout << "2";
				return 0;
			}
			else
				cout << "God";
		}
		
	}
}
