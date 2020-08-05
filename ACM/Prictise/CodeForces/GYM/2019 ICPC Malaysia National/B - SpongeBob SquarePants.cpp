#include<iostream>
using namespace std;

int T,a,b;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        if(a == b) puts("YES");
        else puts("NO");
    }
}