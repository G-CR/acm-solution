#include<bits/stdc++.h>
using namespace std;

int t,n,i;
string s;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int flag = 0;
		scanf("%d",&n);
		cin >> s;
		for(i = 0;i < n-10; i++)
			if(s[i] == '8')
			{
				flag = 1;
				break;
			}
			
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
