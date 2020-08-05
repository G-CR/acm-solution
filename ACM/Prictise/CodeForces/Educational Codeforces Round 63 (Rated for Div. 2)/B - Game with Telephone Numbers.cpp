#include<iostream>
#include<cstring>
using namespace std;

int n,i,j,count;
string s;

int main()
{
	cin >> n >> s;
	for(i = 0;i < (n - 11) + 1; ++i)
		if(s[i] == '8')
			count++;
	if(count >= (n - 11)/2 + 1)
		cout << "YES";
	else
		cout << "NO";
}
