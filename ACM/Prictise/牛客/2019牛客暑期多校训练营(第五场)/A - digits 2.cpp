#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int T,x,t,sum,ans0,ans,i;

int main() 
{
	cin >> T;
	while(T--)
	{
		scanf("%d", &x);
		t = x;
		sum = 0;
		while(t > 0)
		{
			sum += t % 10;
			t /= 10;
		}
		ans0 = sum*x/gcd(max(sum,x),min(sum,x));
		for(i = 1;i <= ans0; i++)
		{
			printf("%d",x);
		}
		cout << endl;
	}
}