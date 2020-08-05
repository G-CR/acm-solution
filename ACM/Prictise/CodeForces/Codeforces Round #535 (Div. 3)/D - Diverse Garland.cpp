#include <bits/stdc++.h>
using namespace std;

int n;
char a[3] = {'R','G','B'};
string s;

int main() {
	scanf("%d", &n);
	cin >> s;
	int sum = 0;
	for(int i = 1;i < n; i++) {
		if(s[i] == s[i-1]) {
			for(int j = 0;j < 3; j++) {
				if(a[j] != s[i-1] && a[j] != s[i+1]) {
					sum++;
					s[i] = a[j];
					break;
				}
			}
		}
	}	
	printf("%d\n", sum);
	cout << s << endl;
}