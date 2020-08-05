#include <iostream>
#include <cstring>
using namespace std;

int q,i,j;
string s,t,p;
bool ok;

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		ok = 1;
		cin >> s >> t >> p;
		
		if(s.length() > t.length()) {puts("NO");continue;}
		
		j = 0;
		for(i = 0;i < t.length(); i++)
		{
			if(s[j] == t[i])
				s[j++] = t[i] = 'A';
		} 
		if(j < s.length()) {puts("NO");continue;}
//		cout << t << endl;
		for(i = 0;i < t.length(); i++)
			for(j = 0;j < p.length(); j++)
				if(p[j] == t[i]) p[j] = t[i] = 'A';
//		cout << t << endl;
		
		for(i = 0;i < t.length(); i++)
			if(t[i] != 'A') {puts("NO"); ok = 0; break;}
			
		if(ok) puts("YES");
	}
}