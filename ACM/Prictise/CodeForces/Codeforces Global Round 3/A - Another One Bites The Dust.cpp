#include<bits/stdc++.h>
using namespace std;

long long a,b,ab,sum;
int main()
{
    cin >> a >> b >> ab;
    sum += 2*ab;
    if(a != b){sum += min(a,b)*2; return cout << ++sum, 0;} 
    else sum += a*2, cout << sum;
}