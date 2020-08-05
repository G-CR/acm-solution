#include<bits/stdc++.h>
using namespace std;

int a[3000],i,j,n;
int sum1,sum2;
int main()
{
    cin >> n;
    for(i = 1;i <= 2*n; i++) cin >> a[i];
    sort(a+1,a+1+2*n);
    for(i = 1;i <= n; i++) sum1 += a[i];
    for(i = n+1; i <= 2*n; i++) sum2 += a[i];
    if(sum1 == sum2) puts("-1");
    else for(i = 1;i <= 2*n; i++) cout << a[i] << " ";
}