#include <bits/stdc++.h>
using namespace std;

string s;
int q, x;
char ch;

int main() {
	cin >> s;
	int sta = 0, n = s.length();
	scanf("%d", &q);
	while(q--) {
		scanf(" %c %d", &ch, &x);
		if(ch == 'A') {
			printf("%c\n", s[(sta+x-1+n)%n]);
		}
		else if(ch == 'M') {
			sta = (sta+x+n)%n;
		}
	}
}