#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,ans=1;
    cin >> n;
    if(n % 2) return putchar('0'), 0;
    for(i = 1;i <= n/2; i++) ans *= 2;
    cout << ans << endl;
}