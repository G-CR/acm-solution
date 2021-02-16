#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int n;
string s;

int main() {
	scanf("%d", &n);
	if(n == 0) return puts("("), 0;
	int a = sqrt(n);
	int b = n / a;
	for(int i = 0;i < a; i++) s += '(';
	for(int i = 0;i < b; i++) s += ')';
	int sheng = n - a*b;
	int pos = s.length()-sheng-1;
	for(int i = 0;i < s.length(); i++) {
		if(i == pos+1) {
			printf("(");
		}
		printf("%c", s[i]);
	}
	puts("");
}