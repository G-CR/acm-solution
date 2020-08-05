#include<iostream>
using namespace std;

int n,i,j,t;

char map[51][51];

int main()
{
	cin >> n;
	for(i = 1;i <= n; ++i)
		for(j = 1;j <= n; ++j)
		{
			cin >> map[i][j];
			if(map[i][j] == '.')
				t++; //记录可放位置的个数 
		}
		
	for(i = 1;i <= n; ++i)
		for(j = 1;j <= n; ++j)
		{
			if(map[i][j] == '#')
				continue;
				
			else
			{
				if(map[i-1][j] == '.' && map[i][j+1] == '.' 
					&& map[i+1][j] == '.' && map[i][j-1] == '.')
				{
					map[i][j] = map[i-1][j] = map[i][j+1] 
					= map[i+1][j] = map[i][j-1] = '#';
					
					t -= 5;
				}
			}
		}
		
//	cout << endl;
//	for(i = 1;i <= n; ++i)
//	{
//		for(j = 1;j <= n; ++j)
//			cout << map[i][j];
//		cout << endl;
//	}
		
		
	if(t != 0)
		cout << "NO";
	else
		cout << "YES";
}
