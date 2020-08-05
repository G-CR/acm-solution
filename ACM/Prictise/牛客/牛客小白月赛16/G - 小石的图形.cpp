#include <iostream>
#include<cmath>
using namespace std;
const double pi = acos(-1);
int main()
{
	double n;
	scanf("%lf", &n);
	printf("%.3lf",n*n/(2.0*pi));
}