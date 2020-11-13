#include <bits/stdc++.h>
using namespace std;

int main() {
    int num[4]; memset(num, 0, sizeof num);
    int n, x;
    scanf("%d", &n);
    for(int i = 1;i <= n; i++) {
        scanf("%d", &x);
        if(x == 1) num[1]++;
        else if(x == 2) num[2]++;
        else num[3]++;
    }
    sort(num+1, num+4);
    printf("%d\n", num[1]+num[2]);
}