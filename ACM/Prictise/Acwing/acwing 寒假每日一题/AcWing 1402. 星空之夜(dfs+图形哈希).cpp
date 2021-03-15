#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[103][103];
vector <pair <int, int> > p;
unordered_map <long long, char> vis;
int tx[] = {0,0,1,1,1,-1,-1,-1};
int ty[] = {-1,1,-1,0,1,-1,0,1};

void dfs(int r, int c) {
	p.push_back({r,c});
	a[r][c] = '0';
	for(int i = 0;i < 8; i++) {
		int tr = r + tx[i];
		int tc = c + ty[i];
		if(a[tr][tc] == '1') dfs(tr, tc);
	}
	return;
}

double getdis(int i, int j) {
	return sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second));
}

long long get_hash() {
	double hash = 0;
	for(int i = 0;i < p.size(); i++) {
		for(int j = i+1;j <p.size(); j++) {
			hash += getdis(i, j);
		}
	}
	return (long long)(hash*10000);
}

void ghs(char c) {
	for(int i = 0;i < p.size(); i++) {
		a[p[i].first][p[i].second] = c;
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	char c = 'a'-1;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(a[i][j] == '1') {
				dfs(i, j);
				double hs = get_hash();
				if(vis[hs]) {
					ghs(vis[hs]);
				}
				else {
					vis[hs] = ++c;
					ghs(c);
				}
				p.clear();
			}
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			printf("%c", a[i][j]);
		}
		puts("");
	}
}