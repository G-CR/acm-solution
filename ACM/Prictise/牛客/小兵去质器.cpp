//https://ac.nowcoder.com/acm/problem/25339
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 4*1e5+10;

int n,k,sum,countl;
char a[N],b[N];

int main()
{
	cin >> n >> k;
	
	for(int i = 1;i <= n; ++i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b+1,b+n+1);
	
	for(int i = 1;i <= k; ++i)
	{
		if(b[i] == b[k])
			countl++;
	}
	
//	cout << "coutl = " << countl << endl;
	for(int i =1;i <= n; ++i)
	{
		if(a[i] <= b[k])
		{
			if(a[i] == b[k] && countl > 0)
			{
				countl--;
				continue;
			}
			if(a[i] < b[k])
				continue;
		}
		
		cout << a[i];
	}
}

