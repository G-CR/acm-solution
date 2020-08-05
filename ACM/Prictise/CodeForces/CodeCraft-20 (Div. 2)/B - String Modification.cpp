#include <bits/stdc++.h>
using namespace std;

string s;
int t, n;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		cin >> s;
		
		int ans = 1;
		string fin = s;
//		cout << "-------" << endl;
		for(int k = 2;k <= n; k++) {
			string res = "";
			if(k == n) {
				for(int i = n-1;i >= 0; i--) res += s[i];
			}
			else {
				for(int i = k-1;i <= n-1; i++) res += s[i];
				if((n-k+1)%2 == 0) for(int i = 0;i < k-1; i++) res += s[i];
				else for(int i = k-2;i >= 0; i--) res += s[i];
			}
						
//			cout <<"k = " << k << " res = " << res << endl;
			if(res < fin) {
				fin = res;
				ans = k;
			}
		}
		
		cout << fin << endl;
		printf("%d\n", ans);
	}
}