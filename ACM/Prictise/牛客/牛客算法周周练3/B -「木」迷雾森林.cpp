#include<bits/stdc++.h>
using namespace std;

const int N=3005;
int f[N][N];
int a[N][N];
int n,m;

template<class T>inline void read(T &res) // 快读
{
	char c;T flag=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
	while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}

int main()
{
	read(n); read(m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			read(a[i][j]);
		} 
	}
	
	f[n][1]=1;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++) {
			 if(a[i+1][j]==0) f[i][j]=(f[i][j]+f[i+1][j])%2333;
			 if(a[i][j-1]==0) f[i][j]=(f[i][j]+f[i][j-1])%2333;
		}
	printf("%d\n", f[1][m]);
}

/*
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int s[3003][3003];

template<class T>inline void read(T &res)
{
	char c;T flag=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
	while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}

void dfs(int x, int y) {
	if(x == n && y == m) {
		ans++;
		ans %= 2333;
		return;
	}
	
	if(x+1 <= n && s[x+1][y] == 0) dfs(x+1, y);
	if(y+1 <= m && s[x][y+1] == 0) dfs(x, y+1);
}

int main() {
	read(n); read(m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			read(s[i][j]);
		}
	}
	dfs(1,1);
	printf("%d\n", ans);
}
*/