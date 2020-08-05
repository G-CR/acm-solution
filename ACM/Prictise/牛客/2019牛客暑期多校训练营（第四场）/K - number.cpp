#include <bits/stdc++.h>
using namespace std;

string s;
int sum,i,cnt[3];
long long ans;

int main()
{
	cin >> s;
	cnt[0] = 1; //细节
	for(i = 0;i <= s.length(); i++)
	{
		if(s[i] == '0') ans++;
		
		sum += (s[i] - '0');
		sum %= 3;
		if(i+1<s.length() && s[i] == '0' && s[i+1] == '0')
		{
			ans += cnt[sum];
		}
		cnt[sum]++;
	}
	cout << ans << endl;
}