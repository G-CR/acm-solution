#include <bits/stdc++.h>
using namespace std;

char a;
string s;

int main() {
	scanf(" %c", &a);
	cin >> s;
	int ans = 0;
	for(char i: s) {
		if(i == a) ans++;
	}
	
	printf("%d\n", ans);
}