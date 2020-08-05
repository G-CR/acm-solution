#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s1[105],s2[105],s12[205],s[205],t1[105],t2[105];
int i,j,T,len,n;
bool ok;

void makeS()
{
	int i, j = 0,k = 0;
	for(i = 0;i < n; i++)
	{
		if(i % 2 == 0) s[i] = s2[j++];
		else s[i] = s1[k++];
	}
	
	j = 0,k = 0;
	for(i = 0;i < n/2; i++) s1[j++] = s[i];
	for(i = n/2;i < n; i++) s2[k++] = s[i];
}

int main() 
{
	scanf("%d", &T);
	for(int p = 1;p <= T; p++)
	{
		int num = 0;
		scanf("%d", &len);
		n = 2*len;
		cin >> s1 >> s2 >> s12;
		strcpy(t1,s1); strcpy(t2,s2);
		
		ok = 1;
		while(strcmp(s,s12))
		{
			makeS();
			if(!strcmp(s1,t1))
				{ok = 0; break;}
			num++;
		}
		
		if(ok) cout << p << " " << num << endl;
		else cout << p << " " << "-1" << endl;
	}
}