#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int>mp;
int n,m,in[10000009],id,k=1,l,r;
int main()
{
    while( cin >> l >> r )
    {
        if( l+r==-2 )    break;
        if( l+r==0 )
        {
            int q=0,w=0,flag=0;
            for(int i=1;i<=id;i++)
            {
                if( in[i]==1 )    q++;
                if( in[i]==0 )    w++;
            }
            if( w==1&&q==id-1 )    flag=1;
            if( id==0 )    flag=1;
            if( flag )    cout << "Case " << k << " is a tree.\n";
            else    cout << "Case " << k << " is not a tree.\n";
            for(int i=1;i<=id;i++)    in[i]=0;
            mp.clear(); id=0; k++;    
        }
        else
        {
            if( !mp[l] )    mp[l]=++id;
            if( !mp[r] )    mp[r]=++id;
            in[ mp[r] ]++;
        }
    }
}