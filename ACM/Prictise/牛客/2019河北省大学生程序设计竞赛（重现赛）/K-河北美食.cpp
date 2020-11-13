#include <bits/stdc++.h>
using namespace std;

int n, m;
map <string, int> ha;
queue <string> q;

int main() {
	scanf("%d %d", &n, &m);
	string name; int num;
	for(int i = 1;i <= n; i++) {
		cin >> name; scanf("%d", &num);
		ha[name] = num;
		q.push(name);
	}
	
	bool ok = 1;
	int cnt;
	for(int i = 1;i <= m; i++) {
		scanf("%d", &cnt);
		for(int j = 1;j <= cnt; j++) {
			cin >> name; scanf("%d", &num);
			if(ha[name] >= num) {
				ha[name] -= num;
			}
			else {
				ok = 0;
				break;
			}
		}
		if(!ok) break;
	}
	
	if(!ok) puts("NO");
	else {
		puts("YES");
		while(!q.empty()) {
			string now = q.front(); q.pop();
			if(ha[now] > 0) {
				cout << now << " " << ha[now] << "\n";
			}
		}
	}
}             