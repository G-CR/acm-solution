#include<bits/stdc++.h>
using namespace std;

long long D,N,S,i,j,f,t,maxi;
int main()
{
    j = 1;
    cin >> D;
    while(D--)
    {
        maxi = 0;
        cin >> N >> S;
        while(N--)
        {
            cin >> f >> t;
            if(t < S) maxi = max(maxi,f);
            else maxi = max(maxi,f-(t-S));
        }
        if(!maxi) cout << "Case #" << j << ": " << "-1" << endl;
        else cout << "Case #" << j << ": " << maxi << endl;
        j++;
    }
}