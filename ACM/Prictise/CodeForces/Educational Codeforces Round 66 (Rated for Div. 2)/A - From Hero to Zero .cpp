#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll n,k,sum;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d %I64d", &n, &k);
        sum = 0;
        while(n > 0)
        {
            sum += n % k;
            n /= k; sum++;
            // cout << "sum = " << sum << " " << "n = " << n << endl;
        }
        printf("%I64d\n",sum-1);
    }
}