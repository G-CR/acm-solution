#include <bits/stdc++.h>
using namespace std;

int m, n, x, num;
bool ok[1005];
queue<int>q;

int main() {
	scanf("%d %d", &m, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(!ok[x]) {
			num++;
			q.push(x);
			ok[x] = 1;
			if(q.size() > m) {
				ok[q.front()] = 0;
				q.pop();
			}
		}
	}
	
	printf("%d\n", num);
}