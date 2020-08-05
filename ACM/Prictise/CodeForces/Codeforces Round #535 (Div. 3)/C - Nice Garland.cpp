#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005],p[200005],ans0[200005];
string t[6] = {"RGB","RBG","GRB","GBR","BGR","BRG"};

int main() {
	scanf("%d", &n);
	cin >> (s+1);
	int ans = 200005+100;
	for(int i = 0 ;i < 6; i++) {
		int sum = 0,k = 0;
		for(int a = 1;a <= n; a++) p[a] = s[a];
		for(int j = 1;j <= n; j++) {
			if(k == 3) k = 0;
			if(s[j] != t[i][k]) {
				sum++;
				p[j] = t[i][k];
			}
			k++;
		}
		if(ans > sum) {
			ans = sum;
			for(int a = 1;a <= n; a++) ans0[a] = p[a];
		}
	}
	printf("%d\n", ans);
	for(int i = 1;i <= n; i++) printf("%c",ans0[i]);
}