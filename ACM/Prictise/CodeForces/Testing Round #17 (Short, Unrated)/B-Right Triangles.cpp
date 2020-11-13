#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1003][1003];
long long l[1003], c[1003];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == '*') {
                l[i]++;
                c[j]++;
            }
        }
    }

    long long ans = 0;
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            if(a[i][j] == '*') {
                ans += (l[i]-1ll)*(c[j]-1ll);
            }
        }
    }

    printf("%lld\n", ans);
}