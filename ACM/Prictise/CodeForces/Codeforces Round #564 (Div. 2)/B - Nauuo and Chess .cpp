#include<bits/stdc++.h>
using namespace std;

int n,i,j,k;
bool ok = false;

int main()
{
    cin >> n;
    for(i = 1;i <= 1000000;i++) if(2*i - 2 >= n-1){k = i;break;}
    cout << k << endl;
    for(i = 1;i <= k; i++)
    {
        cout << "1 " << i << endl; n--;
        if(!n) return 0;
    }
    for(i = 2;i <= k; i++)
    {
        cout << i << " " << k << endl; n--;
        if(!n) return 0;
    }
}