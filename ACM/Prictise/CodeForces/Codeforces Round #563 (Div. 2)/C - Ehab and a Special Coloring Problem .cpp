#include<bits/stdc++.h>
using namespace std;

int n,i,j,k;
int a[100005];

int main()
{
    scanf("%d",&n);
    for(i = 2;i <= n; i++)
    {
        if(a[i] != 0)continue;
        j++;
        for(k = i; k <= n; k += i) a[k] = j;
    }
    for(i = 2;i <= n; i++) printf("%d ",a[i]);
}