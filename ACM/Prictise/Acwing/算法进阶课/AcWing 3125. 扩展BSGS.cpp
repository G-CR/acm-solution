#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e8;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int bsgs(int a, int b, int p) {
    if(1 % p == b % p) return 0;
    int k = sqrt(p) + 1;
    unordered_map<int, int> mp;
    for(int i = 0, j = b % p; i < k; i++, j = (ll)j * a % p) mp[j] = i;
    
    int ak = 1;
    for(int i = 1;i <= k; i++) ak = (ll)ak * a % p;
    
    for(int i = 1, j = ak;i <= k; i++,j = (ll)j * ak % p) {
        if(mp.count(j)) return k * i - mp[j];
        
    }
    return -inf;
}

int exbsgs(int a, int b, int p) {
    b = (b % p + p) % p;
    if(1 % p == b % p) return 0;
    int x, y;
    int d = exgcd(a, p, x, y);
    if(d > 1) {
        if(b % d) return -inf;
        exgcd(a/d, p/d, x, y);
        return exbsgs(a, (ll)b / d * x % (p/d), p/d) + 1;
    }
    return bsgs(a, b, p);
}

int main() {
    int a, p, b;
    while(~scanf("%d %d %d", &a, &p, &b) && a) {
        int res = exbsgs(a, b, p);
        if(res < 0) puts("No Solution");
        else printf("%d\n", res);
    }
    return 0;
}