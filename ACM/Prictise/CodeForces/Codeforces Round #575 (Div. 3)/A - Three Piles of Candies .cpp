#include <iostream>
using namespace std;

int q;
long long a,b,c,sum;

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
			sum = a+b+c;
		printf("%lld\n", sum/2);
	}
}