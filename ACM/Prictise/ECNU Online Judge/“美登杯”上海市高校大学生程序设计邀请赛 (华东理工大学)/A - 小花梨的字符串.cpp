#include<bits/stdc++.h>
using namespace std;

int n, q, l, r, i, j, sum;
string s;

int main()
{
	cin >> n >> q;
	cin >> s;
	for(i = 1;i <= q; i++)
	{
		sum = 0;
		cin >> l >> r;
		int t = r - l + 1;
		for(j = 1;j <= t; j++)
			sum += j;
		cout << sum << endl;
	}
		
		
}
