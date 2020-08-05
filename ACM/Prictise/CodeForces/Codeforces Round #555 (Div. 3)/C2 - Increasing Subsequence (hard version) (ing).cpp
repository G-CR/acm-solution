#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
int n,i,a[N];
char b[N];
int main()
{
    scanf("%d",&n);
    for(i = 1;i <= n; i++) scanf("%d",&a[i]);
    int L = 1,R = n,t = 0,i = 1;
    while(L <= R)
    {
       if(a[L] > t || a[R] > t)
       {
           if(a[L] > t && a[L] <= a[R]){b[i++] = 'L'; t = a[L++];}
           else if(a[R] > t){b[i++] = 'R'; t = a[R--];}
       }
       else break;
    }
    t = i-1;
    printf("%d\n",t);
    for(i = 1;i <= t; i++) printf("%c",b[i]);
}