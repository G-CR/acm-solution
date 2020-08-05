#include <bits/stdc++.h>
using namespace std;

double H,L;

int main() 
{
	cin >> H >> L;
	printf("%.13lf\n",(H*H+L*L)/(2*H)-H);
}