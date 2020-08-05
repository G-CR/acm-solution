#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int T;

int main() 
{
	cin >> T;
	while(T--)
	{
		int num1,num2;
		cin >> s1 >> s2;
		for(int i = s2.length()-1;i >= 0;i--) 
			if(s2[i] == '1')
			{
				num1 = i;
				break;
			}
		int t = s1.length()-s2.length()+num1;
//		cout << "t = " <<t << endl;
		for(int i = t;i >= 0;i--)
		{
			if(s1[i] == '1')
			{
				num2 = i;
				break;
			}
		}
//		cout << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
		cout << t-num2 << endl;
	}
}