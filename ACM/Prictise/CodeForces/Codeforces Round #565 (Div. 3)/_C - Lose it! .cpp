#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int a[N],sum[43],i,j,ans;

int main()
{
    int n;
    cin >> n;
    for(i = 1;i <= n; i++) cin >> a[i];
    if(n < 6) return cout << n << endl, 0;
    for(i = 1;i <= n; i++)
    {
        if(a[i] == 4) sum[4]++;
        else if(a[i] == 8 && sum[4]) sum[4]--,sum[8]++;
        else if(a[i] == 15 && sum[8]) sum[8]--,sum[15]++;
        else if(a[i] == 16 && sum[15]) sum[15]--,sum[16]++;
        else if(a[i] == 23 && sum[16]) sum[16]--,sum[23]++;
        else if(a[i] == 42 && sum[23]) sum[23]--,sum[42]++;
        if(sum[42]) sum[42]--,ans++;
    }
    cout << n - 6*ans << endl;
}