#include <bits/stdc++.h>
using namespace std;

string s;
char a1,a2,a3;
stack <char> q;
int ans;

int main() 
{
	cin >> s;
	for(int i = 0;i < s.length(); i++)
	{
		q.push(s[i]);
		while(q.size() >= 3)
		{
			a1 = q.top(),q.pop(); 
			a2 = q.top(),q.pop(); 
			a3 = q.top(),q.pop();
			if(a1 == a2 && a1 == a3)
			{
				ans++;
				continue;
			}
			else
			{
				q.push(a3); q.push(a2); q.push(a1);
				break;
			}
		}
	}
	cout << ans << endl;
}