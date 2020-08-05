#include<bits/stdc++.h>
using namespace std;

char s[201];

int ok(int st, int en) 
{
	int n = en - st + 1;
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int q = i + j + st;
			if (q > en)
				q = q - en - 1 + st;
			if (s[j + st] > s[q])
				return 0;
			else if (s[j + st] < s[q])
				break;
		}
	}
	return 1;
}

int main() 
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int n = strlen(s);
		int i = 0;
		while (i < n)
		{
			int j = i;
			for (int pos = i + 1; pos < n; pos++)
				if (ok(i, pos))
					j = pos;
			for (int k = i; k <= j; k++)
				printf("%c", s[k]);
			if (j == n - 1)
				puts("");
			else
				printf(" ");
				
			i = j + 1;
		}
	}
}