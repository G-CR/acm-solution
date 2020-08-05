#include <bits/stdc++.h>
using namespace std;

int n;
int a[35][35], b[35][35];

int main() {
	while(~scanf("%d", &n) && n != 0) {
		for(int i = 1;i <= n; i++) 
			for(int j = 1;j <= n; j++) 
				scanf("%d", &a[i][j]);	
		for(int i = 1;i <= n; i++) 
			for(int j = 1;j <= n; j++) 
				scanf("%d", &b[i][j]);
				
		int ans = 0, t = 0, x = 1, y = 1;	
		for(int i = 1,x = 1;i <= n; i++, x++) {
			for(int j = 1,y = 1;j <= n; j++, y++) {
				if(a[x][y] == b[i][j]) t++;
			}
		}
		
		ans = max(ans, t); 
		t = 0;
		
		for(int j = n, x = 1;j >= 1; j--, x++) {
			for(int i = 1,y = 1;i <= n; i++, y++) {
				if(a[x][y] == b[i][j]) t++;
			}
		}	
		
		ans = max(ans, t); 
		t = 0;
		
		for(int i = n,x = 1;i >= 1; i--, x++) {
			for(int j = n,y = 1;j >= 1; j--, y++) {
				if(a[x][y] == b[i][j]) t++;
			}
		}
			
			
		ans = max(ans, t); 
		t = 0;
		
		for(int j = 1,x = 1;j <= n; j++, x++) {
			for(int i = n,y = 1;i >= 1; i--, y++) {
				if(a[x][y] == b[i][j]) t++;
			}
		}
			
		ans = max(ans, t); 
		printf("%d\n", ans);
	}
}