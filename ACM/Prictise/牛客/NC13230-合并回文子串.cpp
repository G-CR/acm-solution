#include<bits/stdc++.h>
using namespace std;

int _, dp[55][55][55][55];
char a[55], b[55];

int main() {
    scanf("%d", &_);
    while(_--) {
        memset(dp, 0, sizeof(dp));
        cin >> (a+1) >> (b+1);
        int ans = 1;
        for(int lena = 0;lena <= strlen(a+1); lena++) {
            for(int lenb = 0;lenb <= strlen(b+1); lenb++) {
                for(int sta = 1;sta+lena-1 <= strlen(a+1); sta++) {
                    for(int stb = 1;stb+lenb-1 <= strlen(b+1); stb++) {
                        int enda = sta+lena-1;
                        int endb = stb+lenb-1;
                        if(lena+lenb <= 1) dp[sta][enda][stb][endb] = 1;
                        else {
                            dp[sta][enda][stb][endb] = 0;
                            if(a[sta] == a[enda]) dp[sta][enda][stb][endb] |= dp[sta+1][enda-1][stb][endb];
                            if(b[stb] == b[endb]) dp[sta][enda][stb][endb] |= dp[sta][enda][stb+1][endb-1];
                            if(a[sta] == b[endb]) dp[sta][enda][stb][endb] |= dp[sta+1][enda][stb][endb-1];
                            if(a[enda] == b[stb]) dp[sta][enda][stb][endb] |= dp[sta][enda-1][stb+1][endb];
                        }
                        
                        if(dp[sta][enda][stb][endb]) ans = max(ans, lena+lenb);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}