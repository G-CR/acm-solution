#include <bits/stdc++.h>
using namespace std;

int n;
char s[100],t[100];

int main() {
	scanf("%d", &n);
	scanf("%s", t+1);
	int j = 0,k = 0;
	for(int i = 1;i <= n; i += k) {
		s[++j] = t[i];
		k++;
	}
	cout << s+1 << endl; 
}