#include <bits/stdc++.h>
using namespace std;

int x,y,z,a,b,c;

int main() {
	scanf("%d %d %d %d %d %d", &x, &y ,&z, &a, &b, &c);
	if(a >= x && a+b-x >= y && a+b+c-x-y >= z) puts("YES");
	else puts("NO");
}