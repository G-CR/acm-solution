#include<iostream>
using namespace std;

int n,m,r,i,j,t,buyMin = 1001,sellMax;
int s[1005],b[1005];

int main()
{
	cin >> n >> m >> r;
	for(i = 1;i <= n; ++i)
	{
		cin >> s[i];
		if(s[i] < buyMin)
			buyMin = s[i];
	}
//	cout << "buyMin = " << buyMin << endl;
	
	for(i = 1;i <= m; ++i)
	{
		cin >> b[i];
		if(b[i] > sellMax)
			sellMax = b[i];
	}
//	cout << "sellMax = " << sellMax << endl;
		
	if(buyMin > sellMax)
	{
		cout << r;
		return 0;
	}
	else
	{
		t = r / buyMin;
//		cout << "t = " << t << endl;
		r -= buyMin * t;
		r += sellMax * t;
		cout << r;
		return 0;
	}
	
}
