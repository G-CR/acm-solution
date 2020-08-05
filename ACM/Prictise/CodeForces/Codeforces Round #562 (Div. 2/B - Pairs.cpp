#include<bits/stdc++.h>
using namespace std;

int a, b, n, m, c, d, i ,j, flag = 1;
int x[300005], y[300005];

int main()
{
    cin >> n >> m;
    cin >> a >> b;
    x[1] = a;y[1] = b;

    for(i = 2;i <= m; i++)
    {
        cin >> x[i] >> y[i];
        if(x[i] != a && x[i] != b && y[i] != a && y[i] != b){c = x[i],d = y[i];}
    }
    
    // cout <<"a = " << a << " " <<"b = " << b << " " <<"c = " << c << " " <<"d = " << d << endl;

    for(i = 1;i <= m; i++)
    {
        if (x[i] == a || y[i] == b || x[i] == b || y[i] == a) continue;
        else
        {
            flag = 0;
            // cout << "! " << x[i] << " " << y[i] << endl;
            break;
        } 
    }
    if(flag) return cout << "YES" << endl, 0;


    flag = 1;
    for(i = 1;i <= m; i++)
    {
        if (x[i] == a || y[i] == c || x[i] == c || y[i] == a) continue;
        else
        {
            flag = 0;
            // cout << "! " << x[i] << " " << y[i] << endl;
            break;
        } 
    }
    if(flag) return cout << "YES" << endl, 0;

    flag = 1;
    for(i = 1;i <= m; i++)
    {
        if (x[i] == a || y[i] == d || x[i] == d || y[i] == a) continue;
        else
        {
            flag = 0;
            // cout << "! " << x[i] << " " << y[i] << endl;
            break;
        } 
    }
    if(flag) return cout << "YES" << endl, 0;

    flag = 1;
    for(i = 1;i <= m; i++)
    {
        if (x[i] == b || y[i] == c || x[i] == c || y[i] == b) continue;
        else
        {
            flag = 0;
            // cout <<"."<< b << " " << c << endl;
            // cout << "! " << x[i] << " " << y[i] << endl;
            break;
        } 
    }
    if(flag) return cout << "YES" << endl, 0;

    flag = 1;
    for(i = 1;i <= m; i++)
    {
        if (x[i] == b || y[i] == d || x[i] == d || y[i] == b) continue;
        else
        {
            flag = 0;
            // cout <<"."<< b << " " << d << endl;
            // cout << "! " << x[i] << " " << y[i] << endl;
            break;
        } 
    }
    if(flag) return cout << "YES" << endl, 0;


    return cout << "NO" << endl, 0;
}