#include <bits/stdc++.h>
using namespace std;

string s,st;
int t,id;

int main() 
{
	scanf("%d", &t);
	for(int p = 1;p <= t; p++)
	{
		int h = 0,d = 0,w = 0;
		cin >> s >> st;
		for(int i = 0;i < s.length(); i++)
		{
			id = s[i]-'a';
			
			if(st[id] == 'd') d++;
			else if(st[id] == 'h') h++;
			else w++;
		}
		printf("Case #%d: ",p);
		
		if(4*h >= s.length()) printf("Harmful\n");
		else if(10*h <= s.length()) printf("Recyclable\n");
		else if(d >= 2*w) printf("Dry\n");
		else printf("Wet\n");
	}
}