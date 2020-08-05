#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q,Count = 0;
    bool ok = true;
    long long n;
    cin >> q;
    while(q--)
    {
        Count = 0;
        cin >> n;ok = true;
        while(n != 1)
        {
            if(n%2 && n%3 && n%5 && n != 1){ok = false;break;}
            if(n % 2 == 0){n /= 2;Count++;} 
            else if(n % 3 == 0){n /= 3;n *= 2;Count++;}
            else if(n % 5 == 0){n /= 5;n *= 4;Count++;}
        }
        if(ok) cout << Count << endl;
        else puts("-1");
    }
}