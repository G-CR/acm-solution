#include <bits/stdc++.h>
using namespace std;

char s[2005];
int num[30], _, n, k;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(num, 0, sizeof(num));
		scanf("%d %d", &n, &k);
		cin >> s;
		for(int i = 0;i < n; i++) {
			num[s[i]-'a'+1]++;
		}
		sort(num+1, num+27, cmp);
		
		int ans = 1;
		for(int i = 1;i <= k; i++) {
			if(k % i) continue;
			for(int j = 1;j <= num[1]; j++) {
				int t = 0;
				for(int l = 1;l <= 26; l++) {
					t += num[l]/j;
				}
				if(t >= i) ans = max(ans, i*j);
			}
		}
		
		printf("%d\n", ans);
	}
}