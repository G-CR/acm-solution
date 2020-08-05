#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;

char f[10],a[N],ch;
int n,i;

int main()
{
    cin >> n;

    getchar();
    for(i = 1;i <= n; i++) cin >> a[i];

    getchar();
    for(i = 1;i <= 9; i++) cin >> f[i];
    
    bool over = false;
    for(i = 1;i <= n; i++)
    {
        if(f[a[i]-'0'] <= a[i] || over){cout << a[i];continue;}
        
        else if(f[a[i]-'0'] > a[i] && !over)
        {
            if((f[a[i+1]-'0'] <= a[i+1]&&f[a[i+2]-'0'] < a[i+2]) || f[a[i+1]-'0'] < a[i+1]) over = true;
            a[i] = f[a[i]-'0'];
        }
        cout << a[i];
        
    }
}