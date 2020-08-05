#include<bits/stdc++.h>
using namespace std;

const long long N = 4294967295;
stack<int > S;
char a[10];
int t;
long long sum,n,loop = 1;
bool ok = true;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a;
        if(a[0] == 'a')
        {
            sum += loop;
            if(sum > N) ok = false;
        }

        else if(a[0] == 'f')
        {
            cin >> n;
            if(n > N) S.push(1);
            else
            {
                loop *= n;
                S.push(n);
            } 
        }

        else
        {
            if(!S.empty())
            {
                loop /= S.top();
                S.pop();
            }
        }   
    }

    if(ok) cout << sum << endl;
    else cout << "OVERFLOW!!!" << endl;
}
