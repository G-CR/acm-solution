#include <bits/stdc++.h>
using namespace std;

int _, n, m, cnt;
string s[105];
struct node {
	int x[4], y[4];
} ans[80000];

void change(int i, int j) {
	s[i][j] = '0';
	s[i+1][j] = s[i+1][j]=='0'?'1':'0';
	ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
	ans[cnt].x[2] = i+1; ans[cnt].y[2] = j;
	if(j > 0) {
		s[i+1][j-1] = s[i+1][j-1]=='0'?'1':'0';
		ans[cnt].x[3] = i+1; ans[cnt].y[3] = j-1;
	} 
	else {
		s[i+1][j+1] = s[i+1][j+1]=='0'?'1':'0';
		ans[cnt].x[3] = i+1; ans[cnt].y[3] = j+1;
	}
}

void change(int i, int j) {
	
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cnt = 0;
		scanf("%d %d", &n, &m);
		for(int i = 0;i < n; i++) {
			cin >> s[i];
		}
		for(int i = 0;i < n; i++) {
			for(int j = 0;j < m; j++) {
				if(i != n-1) {
					if(s[i][j] == '1') change(i, j);
				}
				else {
					if(s[i][j] == '1') {
						s[i][j] = '0';
						if(j < m-1) {
							if(s[i][j+1] == '1') {
								s[i][j+1] = 0;
								ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
								ans[cnt].x[2] = i-1; ans[cnt].y[2] = j;
								ans[cnt].x[3] = i-1; ans[cnt].y[3] = j+1;
								
								ans[++cnt].x[1] = i-1; ans[cnt].y[1] = j;
								ans[cnt].x[2] = i-1; ans[cnt].y[2] = j+1;
								ans[cnt].x[3] = i; ans[cnt].y[3] = j+1;
							}
							else {
								ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
								ans[cnt].x[2] = i-1; ans[cnt].y[2] = j;
								ans[cnt].x[3] = i-1; ans[cnt].y[3] = j+1;
								
								ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
								ans[cnt].x[2] = i; ans[cnt].y[2] = j+1;
								ans[cnt].x[3] = i-1; ans[cnt].y[3] = j+1;
								
								ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
								ans[cnt].x[2] = i-1; ans[cnt].y[2] = j;
								ans[cnt].x[3] = i; ans[cnt].y[3] = j+1;
							}
						}
						else {
							ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
							ans[cnt].x[2] = i-1; ans[cnt].y[2] = j;
							ans[cnt].x[3] = i-1; ans[cnt].y[3] = j-1;
							
							ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
							ans[cnt].x[2] = i; ans[cnt].y[2] = j-1;
							ans[cnt].x[3] = i-1; ans[cnt].y[3] = j;
							
							ans[++cnt].x[1] = i; ans[cnt].y[1] = j;
							ans[cnt].x[2] = i; ans[cnt].y[2] = j-1;
							ans[cnt].x[3] = i-1; ans[cnt].y[3] = j-1;
						}
					}
					
				}
			}
		}
		
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt; i++) {
			printf("%d %d %d %d %d %d\n", ans[i].x[1]+1, ans[i].y[1]+1, ans[i].x[2]+1, ans[i].y[2]+1, ans[i].x[3]+1, ans[i].y[3]+1);
		}
	}
}