#include <bits/stdc++.h>
using namespace std;

string t, s;

int Left(int pos) {
	int sum = 0;
	for(int i = 0;i < pos; i++) {
		if(s[i] == 'Q') sum++;
	}
	return sum;
}

int Right(int pos) {
	int sum = 0;
	for(int i = pos+1;i < s.length(); i++) {
		if(s[i] == 'Q') sum++;
	}
	return sum;
}

int main() {
	cin >> s;
	int ans = 0;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] == 'A') {
			ans += Left(i)*Right(i);
		}
	}
	printf("%d\n", ans);
}