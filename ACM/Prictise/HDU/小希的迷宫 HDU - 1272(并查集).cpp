#include <bits/stdc++.h>
using namespace std;

int fa[100005], u, v;


int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	bool over = 0;
	while(1) {
		for(int i = 1;i <= 1e5; i++) fa[i] = i;
		vector <int> res; res.clear();
		bool ok = 1;
		while(~scanf("%d %d", &u, &v)) {
			if(u == 0 && v == 0) break;
			if(u == -1 && v == -1) {over = 1; break;}
			
			res.push_back(u); res.push_back(v);
			int fu = find(u), fv = find(v);
			if(fu == fv) ok = 0;
			else fa[fu] = fv;
		}
		if(over) break;
		if(res.size() == 0) {puts("Yes"); continue;}
		for(int i = 0;i < res.size(); i++) int tem = find(res[i]);
		int t = find(res[0]);
		
		for(int i = 0;i < res.size(); i++) {
			if(t != find(res[i])) {ok = 0; break;}
		}
		
//		cout << find(5) << " " << find(8) << endl;
		if(ok) puts("Yes");
		else puts("No");
	}
}