#include<iostream>
#include<cstring>
using namespace std;

string s;
int n,i,j,l,r;

int main()
{
	bool ok = false;
	cin >> n >> s;
	
	for(i = 1;i < s.length(); ++i)
	{
		if(s[i] < s[i-1])
		{
			ok = true;
			l = i;
			r = i + 1;
		}
		if(ok)
			break;
	}
	
	if(ok)
		cout << "YES" << endl << l << " " << r << endl;
	else
		cout << "NO";
	
}
