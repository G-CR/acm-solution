#include<bits/stdc++.h>
using namespace std;

int t,n,i,count1,count2,sum;
int a[105];

int main()
{
    cin >> t;
    while(t--)
    {
        count1 = 0,count2 = 0,sum = 0;
        cin >> n;
        for(i = 1;i <= n; i++)
        {
            cin >> a[i];
            if(a[i] % 3 == 1) count1++;
            else if(a[i] % 3 == 2) count2++;
            else sum++;
        }
        if(count2 <= count1)
        {
            sum += count2+(count1-count2)/3;
            cout << sum << endl;
        }
        else
        {
            sum += count1+(count2-count1)/3;
            cout << sum << endl;
        }
    }
}