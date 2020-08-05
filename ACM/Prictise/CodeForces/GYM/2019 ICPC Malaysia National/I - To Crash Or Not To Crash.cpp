#include<bits/stdc++.h>
using namespace std;

char maps[11][11],ans;
int i,j,ti,tj;
bool ok = true,pass = false;

int main()
{
    for(i = 1; i<= 3; i++)
    {
        for(j = 1;j <= 10; j++)
        {
            cin >> maps[i][j];
            if(maps[i][j] == '='){ti = i;tj = j;}
            if(maps[i][j] != '=' && maps[i][j] != '.' && ti == i && !pass){pass = true;ok = false;ans = maps[i][j];}
        }
    }
    if(ok) puts("You shall pass!!!");
    else putchar(ans);
}