#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
int main()
{
	cin >> n;
	while(n--)
	{
		getchar();
		cin >> s;
		int a = s[0] - '0';
		if(a == 1 || a == 3 || a == 5) putchar('E');
		else if(a == 0) putchar('X');
		else putchar('I');
	}
}