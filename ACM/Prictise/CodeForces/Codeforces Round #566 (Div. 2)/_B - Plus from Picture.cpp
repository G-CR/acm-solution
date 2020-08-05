#include<bits/stdc++.h>
using namespace std;
int h,w,i,j,th,tw,sum;
char maps[507][507];

int main()
{
    cin >> h >> w;
    for(i = 1;i <= h; i++)
        for(j = 1;j <= w; j++)
        {
            cin >> maps[i][j];
            if(maps[i][j] == '*') sum++;
        }

    for(i = 1;i <= h; i++)
        for(j = 1;j <= w; j++)
           if(maps[i][j] == '*' && maps[i-1][j] == '*' && maps[i][j-1] == '*' && maps[i+1][j] == '*' && maps[i][j+1] == '*') 
                th = i,tw = j;


    if((h <= 2 || w <= 2) || (th == 0 && tw == 0)) return puts("NO"), 0;

    for(i = tw+1;i <= w; i++) {if(maps[th][i] == '.')break; sum--;} 
    for(i = tw-1;i >= 1; i--) {if(maps[th][i] == '.')break; sum--;} 
    for(i = th+1;i <= h; i++) {if(maps[i][tw] == '.')break; sum--;} 
    for(i = th-1;i >= 1; i--) {if(maps[i][tw] == '.')break; sum--;} 

    if(sum == 1) puts("YES");
    else puts("NO");
}