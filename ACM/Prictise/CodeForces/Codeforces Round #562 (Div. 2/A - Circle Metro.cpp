#include <bits/stdc++.h>
using namespace std;

int n, a, x, b, y, i, j, p, q,flag;
int c[110],d[110];

int main()
{
    cin >> n >> a >> x >> b >> y;
    if(x > a) p = x-a+1;
    else p = n-a+1+x;
    if(b > y) q = b-y+1;
    else q = b+n-y+1;
    for(i = 1;i <= p; i++)
    {
        if(a > n) a = 1;
        c[i] = a++;
    }
    // for(i = 1;i <= p; i++) cout << c[i] << " ";
    // cout << endl;

    for(i = 1;i <= q; i++)
    {
        if(b < 1) b = n;
        d[i] = b--;
    }
    // for(i = 1;i <= q; i++) cout << d[i] << " ";
    // cout << endl;

    i = 1;
    while(i <= p && i <= q)
        if(c[i] == d[i++]){flag = 1;break;}
    // cout << "flag = " << flag << endl;
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}