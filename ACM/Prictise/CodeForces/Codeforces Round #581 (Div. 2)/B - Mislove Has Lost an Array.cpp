#include <bits/stdc++.h>
using namespace std;

int n,l,r;
int a = 1, b = 1;
int main() {
	scanf("%d %d %d",&n, &l, &r);
	for(int i = 1;i < l; i++) a *= 2;
	for(int i = 1;i < r; i++) b *= 2;
	int Min = 0,Max = 0;
	int j = 0;
	for(int i = a;j < n; i /= 2)
	{
		if(i == 0) i = 1;
		Min += i; j++;
	}
	j = 0;
	for(int i = 1;j < n; i *= 2)
	{
		if(i > b) i = b;
		Max += i; j++;
	}
	cout << Min << " " << Max << endl;
}