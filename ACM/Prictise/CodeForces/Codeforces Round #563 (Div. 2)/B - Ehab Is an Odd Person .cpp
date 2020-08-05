#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n,i,j,t;

int main()
{
    cin >> n;
    bool allood = true,alleven = true;
    for(i = 1;i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2) alleven = false;
        else if(!(a[i]%2)) allood = false;
    } 

    if(alleven || allood) for(i = 1;i <= n; i++) cout << a[i] << " ";
    else if(!alleven || !allood)
    {
        sort(a+1,a+1+n);
        for(i = 1;i <= n; i++) cout << a[i] << " ";
    }
    
}