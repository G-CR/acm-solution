#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    if(x==y&&z==0)return putchar('0'),0;
    if(x > y+z) putchar('+');
    else if(y > x+z) putchar('-');
    else putchar('?');
}