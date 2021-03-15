#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, ans;
queue <int> q;
bool vis[1003];

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1;i <= n; i++) {
        scanf("%d", &x);
        if(!vis[x]) {
            ans++;
            if(q.size() == m) {
                vis[q.front()] = 0; 
                q.pop();
            }
            vis[x] = 1; q.push(x);
        }
    }
    printf("%d\n", ans);
}