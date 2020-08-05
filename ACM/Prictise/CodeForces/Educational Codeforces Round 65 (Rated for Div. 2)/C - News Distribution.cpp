#include<bits/stdc++.h>
using namespace std;
const int n = 1e6;

int father[n],Rank[n],a[n],sum[n];
int N,M,i;

int find(int x)
{
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

void unionSet(int x, int y)
{
    if((x = find(x)) == (y = find(y))) return;
    if(Rank[x] > Rank[y])
    {
        father[y] = x;
        sum[x] += sum[y];
    } 
    else
    {
        father[x] = y;
        sum[y] += sum[x];
        if(Rank[x] == Rank[y]) Rank[y]++;
    }
}

int main()
{
    cin >> N >> M;
    for(i = 1;i <= N; i++) sum[i] = 1,father[i] = i;
    while(M--)
    {
        int t;
        cin >> t;
        for(i = 1;i <= t; i++)
        {
            cin >> a[i];
            if(i > 1) unionSet(a[i-1],a[i]);
        }
    }
    for(i = 1;i <= N; i++) cout << sum[find(i)] << " ";
    cout << endl;
}